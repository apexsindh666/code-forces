#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long total_sum = 0;
    int current_min = 1e9; // Initialize with a sufficiently large number
    
    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;
        
        // The final height of this tower will just be the minimum seen so far
        current_min = min(current_min, height);
        total_sum += current_min;
    }
    
    cout << total_sum << "\n";
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