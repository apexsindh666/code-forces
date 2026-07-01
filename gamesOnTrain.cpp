#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int min_h = 7; // Since max value of h_i is 6
    int max_h = 0; // Since min value of h_i is 1
    
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        if (h < min_h) min_h = h;
        if (h > max_h) max_h = h;
    }
    
    // Using the derived logic: k = max_h - min_h + 1
    cout << (max_h - min_h + 1) << "\n";
}

int main() {
    // Optimizing I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}