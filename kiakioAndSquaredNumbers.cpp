#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Compute the sum of squares of the decimal digits of x
long long next_val(long long x) {
    long long sum = 0;
    while (x > 0) {
        long long d = x % 10;
        sum += d * d;
        x /= 10;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        // Any number <= 10^9 reaches its periodic cycle within ~20 steps.
        // Advancing by 200 steps (a multiple of 8, the cycle length)
        // guarantees that two numbers are in-tune iff they end at the same value.
        for (int step = 0; step < 200; ++step) {
            a = next_val(a);
        }

        freq[(int)a]++;
    }

    long long ans = 0;
    for (const auto& [val, count] : freq) {
        ans += 1LL * count * (count - 1) / 2;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}