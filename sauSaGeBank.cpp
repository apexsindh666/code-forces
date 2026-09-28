#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    // One interval takes the remaining days: (n - k + 1)
    // The other (k - 1) intervals take 1 day each, contributing 2 each (2^1 = 2)
    long long ans = (1LL << (n - k + 1)) + 2 * (k - 1);
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}