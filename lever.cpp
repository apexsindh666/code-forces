#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    long long total_decrements = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            total_decrements += (a[i] - b[i]);
        }
    }
    
    // Total iterations = Number of decrements performed + 1 final iteration where Step 1 fails
    cout << total_decrements + 1 << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
