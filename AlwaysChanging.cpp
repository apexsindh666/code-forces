#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total0 = 0, total1 = 0;
    for (char c : s) {
        if (c == '0') total0++;
        else total1++;
    }

    int delta = total0 - total1;

    // DP for subsequences starting with '0':
    // dp00: ends in '0' (length is odd, diff rem0 - rem1 = 1)
    // dp01: ends in '1' (length is even, diff rem0 - rem1 = 0)
    int dp00 = -1, dp01 = -1;

    // DP for subsequences starting with '1':
    // dp11: ends in '1' (length is odd, diff rem0 - rem1 = -1)
    // dp10: ends in '0' (length is even, diff rem0 - rem1 = 0)
    int dp11 = -1, dp10 = -1;

    for (char c : s) {
        if (c == '0') {
            if (dp01 != -1) dp00 = max(dp00, dp01 + 1);
            else dp00 = max(dp00, 1);

            if (dp11 != -1) dp10 = max(dp10, dp11 + 1);
        } else {
            if (dp00 != -1) dp01 = max(dp01, dp00 + 1);

            if (dp10 != -1) dp11 = max(dp11, dp10 + 1);
            else dp11 = max(dp11, 1);
        }
    }

    int max_rem = -1;

    // Check d = 1 (odd length, starts and ends with 0)
    if (abs(delta - 1) <= 1 && dp00 != -1) {
        max_rem = max(max_rem, dp00);
    }

    // Check d = -1 (odd length, starts and ends with 1)
    if (abs(delta - (-1)) <= 1 && dp11 != -1) {
        max_rem = max(max_rem, dp11);
    }

    // Check d = 0 (even length >= 2)
    if (abs(delta - 0) <= 1) {
        if (dp01 != -1) max_rem = max(max_rem, dp01);
        if (dp10 != -1) max_rem = max(max_rem, dp10);
        // Also k = 0 (empty remaining string) is valid if |delta| <= 1
        max_rem = max(max_rem, 0);
    }

    if (max_rem == -1) {
        cout << -1 << "\n";
    } else {
        cout << n - max_rem << "\n";
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