#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Determine the absolute maximum number of upgrades we can make.
    // r(r+1)/2 <= k. For k=360, max_r is 27.
    int max_r = 0;
    while (max_r * (max_r + 1) / 2 <= k) {
        max_r++;
    }

    // Filter the array: Keep at most max_r occurrences of any capacity requirement.
    vector<int> cnt(k + 1, 0);
    vector<pair<int, int>> valid_a;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) continue;
        
        // If we haven't already collected enough elements capable of holding a[i]
        if (cnt[a[i]] < max_r) {
            valid_a.push_back({i, a[i]});
            // This friend can fulfill any capacity requirement from 1 up to a[i]
            for (int x = 1; x <= a[i]; ++x) {
                cnt[x]++;
            }
        }
    }

    // dp[w][m]: max happiness using w cards, with current maximum m
    vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, -INF));
    dp[0][0] = 0;

    for (auto& p : valid_a) {
        int orig_i = p.first;
        int a_i = p.second;
        long long mult = n + 1 - orig_i;

        auto new_dp = dp; // Copy state so we only do at most 1 upgrade per friend

        for (int w_prev = 0; w_prev <= k; ++w_prev) {
            long long max_val = -INF;
            
            for (int m = 1; m <= a_i; ++m) {
                long long current_val = dp[w_prev][m - 1];
                
                // Maintain the prefix maximum in O(1)
                if (current_val != -INF) {
                    max_val = max(max_val, current_val - mult * (m - 1));
                }
                
                // Transition to the new state
                if (max_val != -INF && w_prev + m <= k) {
                    new_dp[w_prev + m][m] = max(new_dp[w_prev + m][m], max_val + mult * m);
                }
            }
        }
        dp = new_dp;
    }

    long long ans = 0;
    for (int w = 0; w <= k; ++w) {
        for (int m = 0; m <= k; ++m) {
            ans = max(ans, dp[w][m]);
        }
    }
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}