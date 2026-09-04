#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 2, 0);
    
    // Frequency array of carrot sizes
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // Prefix sums to quickly count carrots in any range [L, R]
    vector<int> pref(m + 2, 0);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }

    // Helper lambda to query count of elements in range [L, R]
    auto C = [&](int L, int R) {
        if (L > m) return 0;
        R = min(R, m);
        if (L > R) return 0;
        return pref[R] - pref[L - 1];
    };

    // Precalculate Tot[c] = total pieces of size c if we had infinite operations
    // O(M log M) via Harmonic Series
    vector<long long> Tot(m + 2, 0);
    for (int c = 1; c <= m; c++) {
        for (int j = 1; j * c <= m; j++) {
            Tot[c] += 1LL * j * C(j * c, (j + 1) * c - 1);
        }
    }

    // Suffix maximums of Tot array
    vector<long long> SufMaxTot(m + 2, 0);
    for (int c = m; c >= 1; c--) {
        SufMaxTot[c] = max(SufMaxTot[c + 1], Tot[c]);
    }

    // Process each query k independently
    for (int k = 1; k <= m; k++) {
        // If 2^k > m, we can extract the absolute maximum pieces for any c
        if (k >= 20 || (1 << k) > m) {
            cout << SufMaxTot[1] << (k == m ? "" : " ");
            continue;
        }
        
        long long ans_k = 0;
        int limit_c = m / (1 << k);
        
        // Only manually compute F(c, k) for c <= m / 2^k
        for (int c = 1; c <= limit_c; c++) {
            long long res = 0;
            int limit_j = (1 << k) - 1;
            
            // Sum pieces for fully broken down carrots (a_i < 2^k * c)
            for (int j = 1; j <= limit_j; j++) {
                res += 1LL * j * C(j * c, (j + 1) * c - 1);
            }
            
            int L_eq = (1 << k) * c;
            
            // Exact hits (a_i == 2^k * c) yield exactly 2^k pieces
            res += 1LL * (1 << k) * cnt[L_eq];
            
            // Oversized carrots (a_i > 2^k * c) max out at 2^k - 1 pieces
            res += 1LL * ((1 << k) - 1) * C(L_eq + 1, m);
            
            ans_k = max(ans_k, res);
        }
        
        // Maximize against all sizes where 2^k * c > m (using our suffix array)
        if (limit_c + 1 <= m) {
            ans_k = max(ans_k, SufMaxTot[limit_c + 1]);
        }
        
        cout << ans_k << (k == m ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O for CF
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}