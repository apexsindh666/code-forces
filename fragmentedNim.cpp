#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int count_ones = 0;
    int count_large = 0;
    
    for (int i = 0; i < n; ++i) {
        long long stones;
        cin >> stones;
        if (stones == 1) {
            count_ones++;
        } else {
            count_large++;
        }
    }
    
    // Case 1: No large piles exist
    if (count_large == 0) {
        if (count_ones % 2 != 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } 
    // Case 2: Large piles exist
    else {
        if (count_ones % 2 == 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
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