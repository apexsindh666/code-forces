#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a(n);
        bool found = false; // Assume 67 is NOT in the array initially

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            // If we find 67, it is possible to get the product 67
            if (a[i] == 67) {
                found = true;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}