#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    if (!(cin >> n)) return 0;
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    long long min_stolen = LLONG_MAX;
    long long max_stolen = 0;
    for (long long a : divisors) {
        long long remaining = n / a;
        for (long long b : divisors) {
            if (remaining % b == 0) {
                long long c = remaining / b;
                long long current_stolen = (a + 1) * (b + 2) * (c + 2) - n;

                if (current_stolen < min_stolen) min_stolen = current_stolen;
                if (current_stolen > max_stolen) max_stolen = current_stolen;
            }
        }
    }
    cout << min_stolen << " " << max_stolen << "\n";
    return 0;
}