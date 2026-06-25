#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    vector<bool> present(n + 2, false);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= n + 1) {
            present[a[i]] = true;
        }
    }
    
    // Find the MEX of the entire original array
    int entire_mex = 0;
    while (present[entire_mex]) {
        entire_mex++;
    }
    
    // The answer is bounded by the capacity (k - 1) and the original array's MEX
    int ans = min(k - 1, entire_mex);
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