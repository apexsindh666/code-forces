#include <iostream>

using namespace std;

// Standard binary exponentiation
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    long long n, m, r, c;
    cin >> n >> m >> r >> c;
    
    // Calculate total variables and independent equations
    long long total_vars = n * m;
    long long equations = (n - r + 1) * (m - c + 1);
    long long free_vars = total_vars - equations;
    
    long long MOD = 998244353;
    
    // Apply Fermat's Little Theorem to reduce the large exponent
    long long exp = free_vars % (MOD - 1);
    
    // Output 2^exp % MOD
    cout << power(2, exp, MOD) << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}