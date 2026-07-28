#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    // Pigeonhole principle: minimum length can never exceed m
    if (k > m) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        if (i % k == 0) {
            cout << (m + 1 - k);
        } else {
            cout << 1;
        }
        cout << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}