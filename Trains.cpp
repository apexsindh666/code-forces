#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    long long g = __gcd(a, b);
    long long lcm = a / g * b;
    
    long long dasha = 0, masha = 0;
    long long prev = 0;
    long long ia = a, ib = b;
    
    while (ia <= lcm || ib <= lcm) {
        long long t;
        int who; // 0 = Dasha, 1 = Masha
        
        if (ia < ib) {
            t = ia; who = 0;
            ia += a;
        } else if (ib < ia) {
            t = ib; who = 1;
            ib += b;
        } else {
            // Tie: less frequent (higher period) wins
            t = ia;
            who = (a > b) ? 0 : 1;
            ia += a;
            ib += b;
        }
        
        dasha += (who == 0) ? (t - prev) : 0;
        masha += (who == 1) ? (t - prev) : 0;
        prev = t;
    }
    
    if (dasha > masha) cout << "Dasha\n";
    else if (masha > dasha) cout << "Masha\n";
    else cout << "Equal\n";
    
    return 0;
}