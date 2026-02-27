#include <iostream>

using namespace std;

void solve() {
    long long p, q;
    cin >> p >> q;
    if (p < q && 3 * p >= 2 * q) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}