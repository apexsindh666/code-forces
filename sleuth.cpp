#include <bits/stdc++.h>
using namespace std;

void solveSleuth() {
    string S;
    getline(cin, S);  

    for (int i = S.length() - 1; i >= 0; i--) {
        char c = S[i];

        if (isalpha(c)) {
            c = tolower(c);

            if (c == 'a' || c == 'e' || c == 'i' || 
                c == 'o' || c == 'u' || c == 'y') {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            break; 
        }
    }
}

int main() {
    solveSleuth();
    return 0;
}