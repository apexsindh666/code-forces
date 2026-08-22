#include <iostream>
#include <vector>
#include <string>

using namespace std;

static const int MOD = 998244353;
static const int MAXN = 1000005;

long long fact[MAXN];
long long invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c0 = 0, c1 = 0;
    int k0 = 0, k1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') c0++;
        else c1++;

        if (i == 0 || s[i] != s[i - 1]) {
            if (s[i] == '0') k0++;
            else k1++;
        }
    }

    long long ways0 = (k0 == 0) ? 1 : nCr(c0 - 1, k0 - 1);
    long long ways1 = (k1 == 0) ? 1 : nCr(c1 - 1, k1 - 1);

    long long ans = (ways0 * ways1) % MOD;
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}