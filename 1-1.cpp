#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // ---- STEP 1: MAXIMIZE ----
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i <= n - 2; i++) {
            if (s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1') {
                s[i] = '1';
                changed = true;
            }
        }
    }

    int max_score = count(s.begin(), s.end(), '1');

    // ---- STEP 2: MINIMIZE ----
    changed = true;
    while (changed) {
        changed = false;
        for (int i = 1; i <= n - 2; i++) {
            if (s[i] == '1' && s[i - 1] == '1' && s[i + 1] == '1') {
                s[i] = '0';
                changed = true;
            }
        }
    }

    int min_score = count(s.begin(), s.end(), '1');

    cout << min_score << " " << max_score << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}