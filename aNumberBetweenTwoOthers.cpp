#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Answer is NO only when y/x == 2 (no integer strictly between 1 and 2)
        cout << (y / x == 2 ? "NO" : "YES") << "\n";
    }
    
    return 0;
}