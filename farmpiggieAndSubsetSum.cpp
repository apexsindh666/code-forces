#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i += 2) {
            cout << (i + 1) << " " << i << " ";
        }    
        cout << "\n";
        t--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}