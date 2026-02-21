#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // The character at the last index is the only one that cannot be 
    // changed by another, so every other character must become this one.
    char target = s[n - 1];
    int matching_count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == target) {
            matching_count++;
        }
    }

    // Minimum operations = Total length - count of characters already matching target
    cout << n - matching_count << "\n";
}

int main() {
    // Optimizing I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}