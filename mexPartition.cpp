#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O - Essential for MAANG/Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> present(102, false); 
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] <= 101) {
                present[a[i]] = true;
            }
        }
        for (int i = 0; i <= 101; i++) {
            if (!present[i]) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}