#include <bits/stdc++.h>
using namespace std;

const int MOD = 676767677;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        long long ans = 0;
        int last_ge2 = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] >= 2) {
                ans = (ans + a[i]) % MOD;
                last_ge2 = i;
            }
        }
        for (int i = last_ge2 + 1; i < n; i++) {
            if (a[i] == 1) {
                ans = (ans + 1) % MOD;
                break;  
            }
        }

        cout << ans << "\n";
    }
    return 0;
}