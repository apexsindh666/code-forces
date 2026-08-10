#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 1. Calculate the initial compressed length |f(s)|
    int base_len = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            base_len++;
        }
    }

    // 2. Find the maximum reduction possible by deleting s[i] for 1 <= i <= n - 2
    int max_reduction = 0;
    for (int i = 1; i < n - 1; ++i) {
        // Check if s[i] forms a single-character island between its neighbors
        if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
            if (s[i - 1] == s[i + 1]) {
                // Deleting s[i] merges s[i-1] and s[i+1] into one block
                max_reduction = max(max_reduction, 2);
            } else {
                // Deleting s[i] simply removes its block without merging surrounding blocks
                max_reduction = max(max_reduction, 1);
            }
        }
    }

    // 3. Output the minimum compressed length
    cout << base_len - max_reduction << "\n";
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