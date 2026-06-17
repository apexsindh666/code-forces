#include <bits/stdc++.h>
using namespace std;

int main() {
    string g[3];
    for (int i = 0; i < 3; i++) cin >> g[i];

    bool ok = true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (g[i][j] != g[2 - i][2 - j])
                ok = false;

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}