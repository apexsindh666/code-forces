#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int MOD = 998244353;

// Global static arrays to prevent stack overflow and reallocation overhead
int omega_val[MAXN];
int freq[MAXN];
int cnt[MAXN][7];
long long exact_pairs[MAXN][7][7];

// Fast modular exponentiation in O(log exp)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Precompute omega(i) for all numbers up to 200,000 using a Sieve in O(N log log N)
void precompute() {
    for (int i = 2; i < MAXN; i++) {
        if (omega_val[i] == 0) { // i is a prime number
            for (int j = i; j < MAXN; j += i) {
                omega_val[j]++;
            }
        }
    }
}

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    // Clear only the used range [1, n] for the current test case
    for (int i = 1; i <= n; i++) {
        freq[i] = 0;
        for (int w1 = 0; w1 <= 6; w1++) {
            cnt[i][w1] = 0;
            for (int w2 = w1; w2 <= 6; w2++) {
                exact_pairs[i][w1][w2] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        freq[a]++;
    }

    // Step 1: For each divisor d, count multiples categorized by their omega value
    for (int d = 1; d <= n; d++) {
        for (int m = d; m <= n; m += d) {
            if (freq[m] > 0) {
                cnt[d][omega_val[m]] += freq[m];
            }
        }
    }

    // Step 2: Calculate pairs (i < j) that are BOTH multiples of d
    for (int d = 1; d <= n; d++) {
        for (int w1 = 0; w1 <= 6; w1++) {
            for (int w2 = w1; w2 <= 6; w2++) {
                if (w1 == w2) {
                    exact_pairs[d][w1][w2] = (1LL * cnt[d][w1] * (cnt[d][w1] - 1)) / 2;
                } else {
                    exact_pairs[d][w1][w2] = 1LL * cnt[d][w1] * cnt[d][w2];
                }
            }
        }
    }

    // Step 3: Backward DP / Inclusion-Exclusion to isolate exact GCD pairs
    for (int g = n; g >= 1; g--) {
        for (int m = 2 * g; m <= n; m += g) {
            for (int w1 = 0; w1 <= 6; w1++) {
                for (int w2 = w1; w2 <= 6; w2++) {
                    exact_pairs[g][w1][w2] -= exact_pairs[m][w1][w2];
                }
            }
        }
    }

    // Step 4: Precompute powers for bases [0, 12] to avoid redundant modular math
    long long pw[15];
    for (int i = 0; i <= 12; i++) {
        pw[i] = power(i, k);
    }

    // Step 5: Accumulate the final modulo result
    long long total_ans = 0;
    for (int g = 1; g <= n; g++) {
        for (int w1 = 0; w1 <= 6; w1++) {
            for (int w2 = w1; w2 <= 6; w2++) {
                long long p = exact_pairs[g][w1][w2];
                if (p != 0) {
                    // Normalize negative values resulting from integer subtractions
                    p = (p % MOD + MOD) % MOD;
                    int target_omega = w1 + w2 - omega_val[g];
                    total_ans = (total_ans + p * pw[target_omega]) % MOD;
                }
            }
        }
    }

    cout << total_ans << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}