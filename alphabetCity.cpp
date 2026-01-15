#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll m;
    if (!(cin >> n >> m)) return;

    vector<string> names(n);
    vector<vector<int>> counts(n, vector<int>(26, 0));
    vector<ll> total_counts(26, 0);

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        for (char c : names[i]) {
            counts[i][c - 'A']++;
            total_counts[c - 'A']++;
        }
    }

    for (int l = 0; l < n; ++l) {
        ll max_D = 0;
        bool impossible = false;

        for (int c = 0; c < 26; ++c) {
            if (counts[l][c] == 0) continue;

            ll others_count = total_counts[c] - counts[l][c];
            
            if (others_count == 0) {
                impossible = true;
                break;
            }

            // D must be >= ceil(counts[l][c] / others_count)
            ll current_D = (counts[l][c] + others_count - 1) / others_count;
            max_D = max(max_D, current_D);
        }

        if (impossible || max_D > m) {
            cout << -1 << (l == n - 1 ? "" : " ");
        } else {
            cout << m - max_D << (l == n - 1 ? "" : " ");
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}