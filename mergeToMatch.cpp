#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    // Each element in b requires at least 2 elements from a
    if (n < 2 * m) {
        cout << "NO\n";
        return;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    bool possible = true;
    for (int i = 0; i < m; ++i) {
        // Check lower bound with the smallest m elements of a
        // Check upper bound with the largest m elements of a
        if (a[i] >= b[i] || b[i] >= a[n - m + i]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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