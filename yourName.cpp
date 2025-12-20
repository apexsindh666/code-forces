#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        bool possible = true;
        for (int x : freq) {
            if (x != 0) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
