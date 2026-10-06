#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Frequency array since elements are guaranteed to be <= 100
    vector<int> count(105, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    vector<int> ans;
    ans.reserve(n);
    
    // Round-robin descending placement
    while (ans.size() < n) {
        for (int i = 100; i >= 1; i--) {
            if (count[i] > 0) {
                ans.push_back(i);
                count[i]--;
            }
        }
    }

    // Fast I/O printing
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}