#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 4096; // Maximum value of 2^12
const int MAX_K = 12;   // Maximum linear basis dimension / basis size

struct Query {
    int l, r, x, id;
};

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int q;
    if (!(cin >> q)) return 0;

    // Group queries offline by their right endpoint r
    vector<vector<Query>> queries_by_r(n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        queries_by_r[r].push_back({l, r, x, i});
    }

    vector<int> ans(q, 0);

    // dp[k][x] stores the maximum left endpoint l such that 
    // an XOR sum of x can be formed using k elements from [l, r].
    // Placing MAX_V as the second dimension ensures sequential memory access (L1 cache friendly).
    vector<vector<int>> dp(MAX_K + 1, vector<int>(MAX_V, 0));

    // Process array elements from left to right
    for (int r = 1; r <= n; ++r) {
        int v = a[r];
        
        // Transition for k = MAX_K - 1 down to 1
        for (int k = MAX_K - 1; k >= 1; --k) {
            for (int x = 0; x < MAX_V; ++x) {
                if (dp[k][x] > dp[k + 1][x ^ v]) {
                    dp[k + 1][x ^ v] = dp[k][x];
                }
            }
        }
        
        // Base transition: using the single element at current index r (k = 1)
        if (r > dp[1][v]) {
            dp[1][v] = r;
        }

        // Answer all offline queries ending at right endpoint r
        for (const auto& query : queries_by_r[r]) {
            int res = 0;
            // Find the smallest set size k that is valid within range [query.l, r]
            for (int k = 1; k <= MAX_K; ++k) {
                if (dp[k][query.x] >= query.l) {
                    res = k;
                    break;
                }
            }
            ans[query.id] = res;
        }
    }

    // Print all query results
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}