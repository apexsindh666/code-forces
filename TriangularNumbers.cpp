#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int tri = 0;
    for (int k = 1; k <= 500; k++) {
        tri += k;
        if (tri == n) {
            cout << "YES" << endl;
            return 0;
        }
        if (tri > n) break;
    }
    
    cout << "NO" << endl;
    return 0;
}