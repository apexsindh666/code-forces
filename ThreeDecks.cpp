#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        long long total = a + b + c;
        
        // Each deck must have 'target' cards
        // total must be divisible by 3
        // target must be >= b (we can only add to a and b, not remove)
        // target must be < c (we take at least 1 from c)
        
        if (total % 3 == 0) {
            long long target = total / 3;
            if (target >= b && target < c)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}