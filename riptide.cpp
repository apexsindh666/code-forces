#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> tokens(3);
    cin >> tokens[0] >> tokens[1] >> tokens[2];

    int rounds = 0;

    while (true) {
        // Sort to easily identify min, mid, and max elements
        sort(tokens.begin(), tokens.end());

        // Check if any two players have the exact same number of tokens
        if (tokens[0] == tokens[1] || tokens[1] == tokens[2]) {
            break;
        }

        // Max gives 1 token to Min
        tokens[0]++; // min gets 1 token
        tokens[2]--; // max gives 1 token

        rounds++;
    }

    cout << rounds << "\n";
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