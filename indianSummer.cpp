#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<pair<string, string>> unique_leaves;

    while (n--) {
        string species, color;
        cin >> species >> color;
        unique_leaves.insert({species, color});
    }

    cout << unique_leaves.size() << "\n";

    return 0;
}