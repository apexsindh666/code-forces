#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_score = 0;

    if (2LL * k > n + 1) {
        // Case 1: Only the first (n - k + 1) outer pairs are touched
        int limit = n - k + 1;
        for (int i = 0; i < limit; ++i) {
            total_score += max(a[i], a[n - 1 - i]);
        }
    } else {
        // Case 2: The first (k - 1) pairs contribute their max,
        // and all elements from index k to n - k + 1 (1-based) are fully consumed
        for (int i = 0; i < k - 1; ++i) {
            total_score += max(a[i], a[n - 1 - i]);
        }
        for (int i = k - 1; i <= n - k; ++i) {
            total_score += a[i];
        }
    }

    cout << total_score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}