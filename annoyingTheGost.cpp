#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Step 1: Check if a valid matching is possible
    vector<long long> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    for (int i = 0; i < n; ++i) {
        if (sorted_a[i] > b[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    // Step 2: Greedily assign the smallest available valid target index for each a[i]
    vector<int> p(n);
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!used[j] && b[j] >= a[i]) {
                p[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    // Step 3: Count inversions in the permutation p
    int inversions = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i] > p[j]) {
                inversions++;
            }
        }
    }

    cout << inversions << "\n";
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