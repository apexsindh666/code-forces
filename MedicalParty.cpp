#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    string x_prime, y_prime;
    if (!(cin >> x_prime >> y_prime)) return;
    
    int n = x_prime.length();
    
    // dp[0] represents min flips for y_i = 0
    // dp[1] represents min flips for y_i = 1
    // Base case: conceptually before index 0, y_0 = 0 with 0 flips.
    int dp_0 = 0;
    int dp_1 = INF;
    
    for (int i = 0; i < n; ++i) {
        int next_dp_0 = INF;
        int next_dp_1 = INF;
        
        int x_curr = x_prime[i] - '0';
        int y_curr = y_prime[i] - '0';
        
        // Try setting current y_i to 'b' (0 or 1)
        for (int b = 0; b <= 1; ++b) {
            // Try all possible values for previous y_{i-1} (prev_b)
            for (int prev_b = 0; prev_b <= 1; ++prev_b) {
                int prev_val = (prev_b == 0) ? dp_0 : dp_1;
                if (prev_val == INF) continue;
                
                // x_i is uniquely determined by y_i ^ y_{i-1}
                int expected_x = b ^ prev_b;
                
                // Calculate mismatched bits (cost)
                int cost_x = (expected_x != x_curr) ? 1 : 0;
                int cost_y = (b != y_curr) ? 1 : 0;
                
                if (b == 0) {
                    next_dp_0 = min(next_dp_0, prev_val + cost_x + cost_y);
                } else {
                    next_dp_1 = min(next_dp_1, prev_val + cost_x + cost_y);
                }
            }
        }
        
        dp_0 = next_dp_0;
        dp_1 = next_dp_1;
    }
    
    cout << min(dp_0, dp_1) << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}