#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Print the first 'n' odd numbers
    for (int i = 1; i <= n; i++) {
        cout << (2 * i - 1) << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O for optimal performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}