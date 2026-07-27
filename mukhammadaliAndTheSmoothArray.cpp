#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Fenwick tree (Binary Indexed Tree) for range prefix maximum query
struct Fenwick {
    int n;
    vector<long long> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] = max(tree[idx], val);
        }
    }

    long long query(int idx) {
        long long mx = 0;
        for (; idx > 0; idx -= idx & -idx) {
            mx = max(mx, tree[idx]);
        }
        return mx;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), c(n);
    long long total_cost = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        total_cost += c[i];
    }

    // Coordinate Compression on array 'a'
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();
    Fenwick bit(m);

    long long max_keep_cost = 0;

    for (int i = 0; i < n; ++i) {
        // Get 1-based compressed index
        int idx = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
        
        // Find best DP value for any <= a[i]
        long long best_prev = bit.query(idx);
        long long current_dp = best_prev + c[i];

        max_keep_cost = max(max_keep_cost, current_dp);
        bit.update(idx, current_dp);
    }

    cout << total_cost - max_keep_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}