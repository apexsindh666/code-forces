#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string leader;
    int maxScore = INT_MIN;

    for (int i = 0; i < n; i++) {
        string handle;
        int plusi, minusi;
        int a, b, c, d, e;

        cin >> handle >> plusi >> minusi >> a >> b >> c >> d >> e;

        int score = a + b + c + d + e + (plusi * 100) - (minusi * 50);

        if (score > maxScore) {
            maxScore = score;
            leader = handle;
        }
    }

    cout << leader << endl;

    return 0;
}