#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (k < n || k > 2 * n - 1) {
        cout << -1 << "\n";
        return;
    }
    
    vector<vector<int>> a(n, vector<int>(n, 0));
    
    int S = 2 * n - k;
    int val = 1;
    
    // 1. Shared minimums on the diagonal
    for (int i = 0; i < S; ++i) {
        a[i][i] = val++;
    }
    
    // 2. Exclusive row minimums in column S-1
    for (int i = S; i < n; ++i) {
        a[i][S - 1] = val++;
    }
    
    // 3. Exclusive col minimums in row S-1
    for (int j = S; j < n; ++j) {
        a[S - 1][j] = val++;
    }
    
    // 4. Fill the remaining zeros
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                a[i][j] = val++;
            }
        }
    }
    
    // Print the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
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