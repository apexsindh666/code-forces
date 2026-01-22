#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Condition 1: Check if it contains "2026"
    bool has2026 = (s.find("2026") != string::npos);

    // Condition 2: Check if it contains "2025"
    bool has2025 = (s.find("2025") != string::npos);

    // Logic: 
    // A string is "New Year" if (has2026) OR (!has2025).
    if (has2026 || !has2025) {
        cout << 0 << endl;
    } else {
        // If it fails both, it means it has "2025" and NO "2026".
        // Changing one '5' to '6' in "2025" makes it "2026".
        // Cost is always 1.
        cout << 1 << endl;
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