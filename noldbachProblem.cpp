#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Step 1: Sieve of Eratosthenes
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Store primes
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    // Step 2: Check condition
    int count = 0;
    for (int i = 0; i < (int)primes.size() - 1; i++) {
        int x = primes[i] + primes[i + 1] + 1;
        if (x <= n && isPrime[x]) {
            count++;
        }
    }

    // Step 3: Output result
    if (count >= k) cout << "YES";
    else cout << "NO";

    return 0;
}