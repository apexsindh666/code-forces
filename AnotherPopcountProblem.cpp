#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long total_popcount = 0;
    long long current_power = 1; // Represents 2^j, starting at 2^0 = 1
    
    // Greedily take bits from smallest power to largest
    while (n > 0 && current_power <= n) {
        // Find how many times we can afford to take this bit power
        long long max_usable = n / current_power;
        
        // We can take it at most k times, or as many times as we can afford
        long long take = min(k, max_usable);
        
        total_popcount += take;
        n -= take * current_power;
        
        // Move to the next bit power (2^j)
        // Using a check to prevent overflow if current_power gets too large
        if (current_power > n) break; 
        current_power *= 2;
    }
    
    cout << total_popcount << "\n";
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