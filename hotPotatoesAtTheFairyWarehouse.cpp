#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k; // k is read but logically ignored based on optimal play
    string s;
    cin >> s;
    
    int red_score = 0;
    int blue_score = 0;
    int len = 2 * n;
    
    // Simulate the exact equivalent of playing just 1 round
    for (int i = 0; i < len; ++i) {
        if (s[i] == '1') {
            int nxt = (i + 1) % len;
            int final_pos = i;
            
            // The potato moves forward if the next space is empty
            if (s[nxt] == '0') {
                final_pos = nxt;
            }
            
            // 0-indexed final_pos translates to (final_pos + 1) in 1-indexed.
            // Red scores if the 1-indexed position is Even.
            // Blue scores if the 1-indexed position is Odd.
            if (final_pos % 2 != 0) {
                red_score++;
            } else {
                blue_score++;
            }
        }
    }
    cout << red_score << " " << blue_score << "\n";
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