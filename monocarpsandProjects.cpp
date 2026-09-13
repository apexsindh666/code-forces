#include <iostream>
#include <algorithm>

using namespace std;

// Computes sum of integers from l to r without 64-bit overflow
inline unsigned long long range_sum(unsigned long long l, unsigned long long r) {
    if (l > r) return 0;
    unsigned long long sum = l + r;
    unsigned long long count = r - l + 1;
    if (sum % 2 == 0) {
        sum /= 2;
    } else {
        count /= 2;
    }
    return sum * count;
}

void solve() {
    long long x, y, k;
    cin >> x >> y >> k;

    long long D = y - x;
    long long L = x;
    long long R = x + k - 1;

    unsigned long long total_projects = 0;

    // Part 1: Range where m <= D
    long long right_bound = min(R, D);
    if (L <= right_bound) {
        long long cur = L;
        while (cur <= right_bound) {
            long long q = D / cur;
            long long next_m = (q == 0) ? right_bound : min(right_bound, D / q);

            unsigned long long count = next_m - cur + 1;
            unsigned long long sum_m = range_sum(cur, next_m);

            total_projects += (unsigned long long)D * count - (unsigned long long)q * sum_m;
            cur = next_m + 1;
        }
    }

    // Part 2: Range where m > D (here D mod m = D)
    long long left_bound = max(L, D + 1);
    if (left_bound <= R) {
        unsigned long long count = R - left_bound + 1;
        total_projects += (unsigned long long)D * count;
    }

    cout << total_projects << "\n";
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