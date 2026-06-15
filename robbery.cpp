#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    long long min_odd_val = 1e18; // Use a large number to find the minimum
    
    for (int i = 0; i < n; ++i) {
        long long diamonds;
        cin >> diamonds;
        
        // 1-based odd positions correspond to 0-based even indices (0, 2, 4...)
        if (i % 2 == 0) {
            min_odd_val = min(min_odd_val, diamonds);
        }
    }

    // If n is even, the alternating ripple effect yields 0 net stolen diamonds
    if (n % 2 == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Calculate bottlenecks using long long to prevent integer overflow
    long long ops_per_diamond = (n / 2) + 1;
    long long diamonds_per_minute = m / ops_per_diamond;
    long long max_stolen_capacity = k * diamonds_per_minute;

    // The result is the bottleneck between his max capacity and the odd-cell limit
    long long max_loot = min(min_odd_val, max_stolen_capacity);
    
    cout << max_loot << "\n";

    return 0;
}