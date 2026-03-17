#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), d(n), target(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> d[i];
        target[i] = x[i] + d[i];
    }

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (target[i] == x[j] && target[j] == x[i]) {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }

    if (found)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}