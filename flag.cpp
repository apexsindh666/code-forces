#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> flag(n);
    for (int i = 0; i < n; i++) {
        cin >> flag[i];
    }

    for (int i = 0; i < n; i++) {
        // Check if row has same color
        for (int j = 1; j < m; j++) {
            if (flag[i][j] != flag[i][0]) {
                cout << "NO";
                return 0;
            }
        }

        // Check if adjacent rows have different colors
        if (i > 0 && flag[i][0] == flag[i-1][0]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}