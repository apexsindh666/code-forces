#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;

    // Iterate through each farm in blocks of size k
    for (int i = 0; i < n; i += k) {
        bool has_zero = false;
        
        for (int j = 0; j < k; ++j) {
            if (s[i + j] == '0') {
                has_zero = true;
                break;
            }
        }
        
        // If every field in this farm is '1', we are forced to build on Nhoj's land
        if (!has_zero) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}