#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        set<int> received;
        int pos = 0; // 0-indexed, student 1 starts with ball

        received.insert(pos);

        for (int i = 0; i < n; i++) {
            if (s[pos] == 'R') pos++;
            else pos--;
            received.insert(pos);
        }

        cout << received.size() << "\n";
    }

    return 0;
}