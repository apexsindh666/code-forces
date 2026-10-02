#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    int ans = 0;
    int l = 0, r = n - 1;

    while (l < r) {
        if (s[l] != s[r]) {
            // If at least one of them is already 'c', we only need 1 coin
            // to turn the other one into 'c'.
            // Otherwise, both need to be replaced by 'c' (2 coins).
            if (s[l] == c || s[r] == c) {
                ans += 1;
            } else {
                ans += 2;
            }
        }
        l++;
        r--;
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