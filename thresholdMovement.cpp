#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    // Condition 1: n must be even
    if (n % 2 != 0) {
        cout << "NO\n";
        return;
    }

    long long min_odd = 2e18; // Infinity
    long long max_even = -1;

    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            min_odd = min(min_odd, w[i]);
        } else {
            max_even = max(max_even, w[i]);
        }
    }

    // Condition 2: Check if an integer k strictly between max_even and min_odd exists
    if (min_odd - max_even >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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