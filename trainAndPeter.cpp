#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, s1, s2;
    cin >> s >> s1 >> s2;
    bool forward = false;
    size_t pos1 = s.find(s1);
    if (pos1 != string::npos) {
        size_t pos2 = s.find(s2, pos1 + s1.size());
        if (pos2 != string::npos) {
            forward = true;
        }
    }
    string rev = s;
    reverse(rev.begin(), rev.end());
    bool backward = false;
    pos1 = rev.find(s1);
    if (pos1 != string::npos) {
        size_t pos2 = rev.find(s2, pos1 + s1.size());
        if (pos2 != string::npos) {
            backward = true;
        }
    }
    if (forward && backward) cout << "both\n";
    else if (forward) cout << "forward\n";
    else if (backward) cout << "backward\n";
    else cout << "fantasy\n";

    return 0;
}