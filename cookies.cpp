#include <iostream>

using namespace std;

/**
 * Problem: A. Cookies
 * Logic: The number of empty cells follows a recursive tripling pattern.
 * For n = 1, empty = 1.
 * For n = 2, empty = 3.
 * For n = 3, empty = 9.
 * Formula: 3^(n-1) % 1000003 for n >= 1. 
 * For n = 0, the answer is 1.
 */

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1000003;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    if (n == 0) {
        cout << 1 << endl;
    } else {
        // The pattern starts at n=1 (3^0), n=2 (3^1), n=3 (3^2)
        cout << power(3, n - 1) << endl;
    }

    return 0;
}