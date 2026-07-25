#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long MOD_EXP = 1e9 + 6; // Fermat's Little Theorem modulo (MOD - 1)

// Fast modular exponentiation
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

// Modular inverse using Fermat's Little Theorem
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

struct Node {
    long long val;
    int cnt;
    int time_created;
};

void solve() {
    int q;
    if (!(cin >> q)) return;

    long long L_val = 0;       // L mod (10^9 + 7)
    long long L_exp = 0;       // L mod (10^9 + 6)
    int L_parity = 0;          // 0 for even length, 1 for odd length
    long long Sum = 0;         // Total sum of elements mod (10^9 + 7)
    int max_time = 0;          // Tracks operation ID for Type 2 queries

    vector<long long> val_by_time(q + 1, 0);
    deque<Node> dq;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            // Erase middle element
            Node& u = dq.front();
            Sum = (Sum - u.val + MOD) % MOD;
            L_val = (L_val - 1 + MOD) % MOD;
            L_exp = (L_exp - 1 + MOD_EXP) % MOD_EXP;
            L_parity ^= 1;

            u.cnt--;
            if (u.cnt == 0) {
                int t_created = u.time_created;
                dq.pop_front();
                
                // CRITICAL FIX: Push in increasing timestamp order so the newest
                // insertion (max_time) ends up at the very front of the deque!
                for (int t = t_created + 1; t <= max_time; t++) {
                    dq.push_front({val_by_time[t], 2, t});
                }
            }
        } 
        else if (type == 2) {
            long long x;
            cin >> x;
            max_time++;
            val_by_time[max_time] = x;

            // Safe modulo arithmetic to prevent 64-bit overflow
            long long added_count = (L_val + 1) % MOD;
            Sum = (Sum + (added_count * (x % MOD)) % MOD) % MOD;
            
            // If length was even, the new element lands directly at the unique center
            if (L_parity == 0) {
                dq.push_front({x, 1, max_time});
            }
            // If length was odd, x surrounds the existing center; handled lazily via timestamps

            L_val = (2 * L_val + 1) % MOD;
            L_exp = (2 * L_exp + 1) % MOD_EXP;
            L_parity = 1; // 2L + 1 is always odd
        } 
        else if (type == 3) {
            if (L_val == 0 && L_parity == 0) {
                cout << 0 << "\n";
                continue;
            }
            // Closed-form: Sum * (2^(L-2) + (2^L - 1) / (2L)) mod MOD
            long long term1 = power(2, (L_exp - 2 + MOD_EXP) % MOD_EXP);
            long long term2 = (power(2, L_exp) - 1 + MOD) % MOD;
            term2 = (term2 * modInverse((2 * L_val) % MOD)) % MOD;

            long long ans = (Sum * ((term1 + term2) % MOD)) % MOD;
            cout << ans << "\n";
        }
    }
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}