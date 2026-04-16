#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        
        ll P0 = 0;  // max position reachable with 0 rollbacks
        ll D = 0;   // best net gain per rollback cycle
        
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            P0 += (b - 1) * a;         // free jumps before first rollback
            D = max(D, b * a - c);     // net gain of one rollback cycle
        }
        
        if (P0 >= x) {
            cout << 0 << "\n";
        } else if (D <= 0) {
            cout << -1 << "\n";
        } else {
            ll need = x - P0;
            ll ans = (need + D - 1) / D;  // ceil division
            cout << ans << "\n";
        }
    }
    return 0;
}