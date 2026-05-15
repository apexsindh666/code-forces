#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        
        for (int i = 1; i <= n; i++) {
            int pi   = (i   != r) ? i     : l - 1;
            int pi_1 = (i-1 != r) ? i - 1 : l - 1;
            cout << (pi ^ pi_1);
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}