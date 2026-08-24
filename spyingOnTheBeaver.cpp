#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        children[p[i]].push_back(i);
    }

    int m;
    cin >> m;
    vector<bool> is_dam(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        is_dam[a] = true;
    }

    // dp[u] represents the number of "distinguishable active branches" 
    // coming up from the subtree of u.
    // has_dam_in_subtree[u] tracks if any dam exists in u's subtree.
    vector<bool> has_dam(n + 1, false);
    vector<int> cameras;

    // Process bottom-up: Since p[i] < i, iterating from n down to 1 
    // guarantees post-order processing.
    for (int u = n; u >= 1; --u) {
        if (is_dam[u]) {
            has_dam[u] = true;
        }

        vector<int> active_children;
        for (int v : children[u]) {
            if (has_dam[v]) {
                active_children.push_back(v);
                has_dam[u] = true;
            }
        }

        int c = active_children.size();
        if (c == 0) continue;

        if (is_dam[u]) {
            // Need a camera on every active child branch to distinguish 
            // staying at u vs going down to any child.
            for (int v : active_children) {
                cameras.push_back(v);
            }
        } else {
            // If c >= 2, we must place cameras on c - 1 branches to uniquely
            // identify which branch was taken.
            for (int i = 0; i < c - 1; ++i) {
                cameras.push_back(active_children[i]);
            }
        }
    }

    // Output result
    cout << cameras.size();
    for (int node : cameras) {
        cout << " " << node;
    }
    cout << "\n";
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