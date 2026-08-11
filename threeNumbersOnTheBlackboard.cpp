#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    // Sort so that a[0] <= a[1] <= a[2]
    sort(a, a + 3);
    
    long long x = a[0];
    long long y = a[1];
    long long z = a[2];
    
    // Option 1: Perform 0 operations -> range is max - min = z - x
    long long range0 = z - x;
    
    // Option 2: Replace z with x + y -> new triplet is (x, y, x + y)
    // Range becomes (x + y) - x = y
    long long range1 = y;
    
    // Output the minimum of both options
    cout << min(range0, range1) << "\n";
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