#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        initial_sum += val;
    }
    
    // 1. If length is odd, it's impossible to balance 1s and -1s evenly
    // 2. The operation changes the sum by multiples of 4, so initial_sum must be divisible by 4
    if (n % 2 != 0 || initial_sum % 4 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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