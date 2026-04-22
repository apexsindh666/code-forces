#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> min_viability(m + 1, LLONG_MAX);

    for (int i = 0; i < n; i++) {
        int r;
        long long c;
        cin >> r >> c;
        min_viability[r] = min(min_viability[r], c);
    }

    long long total = 0;

    for (int i = 1; i <= m; i++) {
        total += min_viability[i];
    }

    cout << min(total, k) << endl;

    return 0;
}