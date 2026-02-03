#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int l = -1, r = -1;

        // Find first position where permutation is not already optimal
        for (int i = 0; i < n; i++) {
            if (p[i] != n - i) {
                l = i;
                break;
            }
        }

        if (l != -1) {
            // Find position of the value (n - l)
            for (int i = l; i < n; i++) {
                if (p[i] == n - l) {
                    r = i;
                    break;
                }
            }
            reverse(p.begin() + l, p.begin() + r + 1);
        }

        for (int x : p) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
