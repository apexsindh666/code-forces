#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    // Alice either takes all stones: a + c - b
    // or passes (takes 0) when b > a, leaving Bob unable to reduce below b - a:
    long long ans = max(b - a, a + c - b);
    
    cout << ans << "\n";
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