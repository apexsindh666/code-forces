#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to count valid pattern assignments for a single parity subsequence
int count_valid_patterns(const string& sub) {
    int ways = 0;

    // Check Pattern A: 0, 1, 0, 1, ...
    bool pattern_A_valid = true;
    for (int i = 0; i < sub.length(); ++i) {
        char expected = (i % 2 == 0) ? '0' : '1';
        if (sub[i] != '?' && sub[i] != expected) {
            pattern_A_valid = false;
            break;
        }
    }
    if (pattern_A_valid) ways++;

    // Check Pattern B: 1, 0, 1, 0, ...
    bool pattern_B_valid = true;
    for (int i = 0; i < sub.length(); ++i) {
        char expected = (i % 2 == 0) ? '1' : '0';
        if (sub[i] != '?' && sub[i] != expected) {
            pattern_B_valid = false;
            break;
        }
    }
    if (pattern_B_valid) ways++;

    return ways;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string odd_sub = "";
    string even_sub = "";

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            odd_sub += s[i];  // 0-indexed: 0, 2, 4, ...
        } else {
            even_sub += s[i]; // 0-indexed: 1, 3, 5, ...
        }
    }

    long long w_odd = count_valid_patterns(odd_sub);
    long long w_even = count_valid_patterns(even_sub);

    long long ans = (w_odd * w_even) % 998244353;
    cout << ans << "\n";
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