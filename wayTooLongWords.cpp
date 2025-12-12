#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.length() <= 10) {
            cout << s << endl;
        } else {
            string r = string(1, s[0]) + to_string(s.length() - 2) + string(1, s[s.length() - 1]);
            cout << r << endl;
        }
    }

    return 0;
}
