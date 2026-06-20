#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    
    long long k1 = 0; // Number of valid shifts between a and b
    for (int shift = 0; shift < n; ++shift) {
        bool valid = true;
        for (int m = 0; m < n; ++m) {
            if (a[m] >= b[(m + shift) % n]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            k1++;
        }
    }
    
    long long k2 = 0; // Number of valid shifts between b and c
    for (int shift = 0; shift < n; ++shift) {
        bool valid = true;
        for (int x = 0; x < n; ++x) {
            if (b[x] >= c[(x + shift) % n]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            k2++;
        }
    }
    
    // Total combinations = n * k1 * k2
    long long ans = (long long)n * k1 * k2;
    cout << ans << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}