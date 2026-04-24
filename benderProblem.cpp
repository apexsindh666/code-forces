#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<long long> rods(m);
    for (int i = 0; i < m; i++) cin >> rods[i];

    // Distance between nail a and nail b (axis-aligned so Manhattan = Euclidean)
    auto dist = [&](int a, int b) -> long long {
        return abs(x[a] - x[b]) + abs(y[a] - y[b]);
    };

    // Try both alternating patterns: fold nails start at 0 or 1
    for (int start = 0; start <= 1; start++) {
        // Build availability map: length -> list of rod indices (1-based)
        map<long long, vector<int>> avail;
        for (int i = 0; i < m; i++)
            avail[rods[i]].push_back(i + 1);

        vector<int> assignment(n, -1);
        bool ok = true;

        for (int k = 0; k < n / 2; k++) {
            int i    = start + 2 * k;
            int prev = (i - 1 + n) % n;
            int next = (i + 1) % n;
            long long need = dist(i, prev) + dist(i, next);

            auto it = avail.find(need);
            if (it == avail.end() || it->second.empty()) {
                ok = false;
                break;
            }
            assignment[i] = it->second.back();
            it->second.pop_back();
        }

        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << assignment[i] << " \n"[i == n - 1];
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}