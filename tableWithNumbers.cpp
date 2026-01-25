#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O for competitive programming [cite: 80]
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        
        int r = 0; 
        int c = 0; 
        int total_valid = 0; // Numbers that can be either a row OR a column
        
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            bool can_be_row = (val <= h);
            bool can_be_col = (val <= l);
            
            if (can_be_row) r++;
            if (can_be_col) c++;
            if (can_be_row || can_be_col) total_valid++; // Must be valid for at least one
        }

        // The limit is the minimum of:
        // 1. Available row indices
        // 2. Available column indices
        // 3. Pairs formed by total valid physical elements (total_valid / 2)
        int res = min(r, min(c, total_valid / 2)); 
        
        cout << res << "\n";
    }
    return 0;
}