#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    bool adjacent_zeros = false;
    bool all_ones = true;
    int prev_a = -1;
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        
        // If we find a 0, then not everyone won
        if (a == 0) {
            all_ones = false;
            // Check for adjacent 0s
            if (prev_a == 0) {
                adjacent_zeros = true;
            }
        }
        prev_a = a;
    }
    
    // If either impossible condition is met, at least one player lied
    if (adjacent_zeros || all_ones) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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