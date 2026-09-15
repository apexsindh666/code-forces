#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int ones_count = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            ones_count++;
        }
    }
    
    // Calculate how many turns Elsie gets in total
    int elsie_turns = (n - 1) / 2; 
    
    // If Bessie has more 1s than Elsie has turns to destroy them, Bessie wins
    if (ones_count > elsie_turns) {
        cout << "Bessie\n";
    } else {
        cout << "Elsie\n";
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