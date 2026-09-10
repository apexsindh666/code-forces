#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int zero_count = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            zero_count++;
        }
    }
    
    // It is impossible if there are fewer than two easy problems in total.
    if (zero_count < 2) {
        cout << -1 << "\n";
        return;
    }
    
    // If enough zeros exist, we simply count how many ends (first and last) are currently '1'.
    int operations = a[0] + a[n - 1];
    cout << operations << "\n";
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