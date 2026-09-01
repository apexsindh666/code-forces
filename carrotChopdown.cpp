#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> freq(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        freq[a]++;
    }

    // Suffix sum of frequencies: suffix[i] = count of elements >= i
    vector<int> suffix(m + 2, 0);
    for (int i = m; i >= 1; --i) {
        suffix[i] = suffix[i + 1] + freq[i];
    }

    int max_carrots = 0;

    // Strategy 1: Target length is equal to cut size x
    // Any element >= x gives at least 1 piece of size x.
    // Any element == 2x gives 2 pieces of size x (1 extra piece).
    for (int x = 1; x <= m; ++x) {
        int count_2x = (2 * x <= m) ? freq[2 * x] : 0;
        int current = suffix[x] + count_2x;
        max_carrots = max(max_carrots, current);
    }

    // Strategy 2: Target length is different from cut size x
    // Combine the carrots from the two most frequent original lengths
    int max1 = 0, max2 = 0;
    for (int i = 1; i <= m; ++i) {
        if (freq[i] > max1) {
            max2 = max1;
            max1 = freq[i];
        } else if (freq[i] > max2) {
            max2 = freq[i];
        }
    }

    max_carrots = max(max_carrots, max1 + max2);

    cout << max_carrots << "\n";
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