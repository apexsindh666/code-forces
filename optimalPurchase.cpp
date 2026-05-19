#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        
        long long full = n / 3;
        long long rem  = n % 3;
        
        long long cost = full * min(b, 3 * a);
        if (rem > 0)
            cost += min(b, rem * a);
        
        cout << cost << "\n";
    }
    return 0;
}