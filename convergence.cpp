#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // The optimal target location will always be one of the existing friend positions.
    // We can try making each a[i] the target 'X' and find the one that minimizes max(L, R).
    int min_calls = n; // Initialize with a safe upper bound (at most n calls are needed)
    
    for (int i = 0; i < n; i++) {
        long long target = a[i];
        int left_count = 0;
        int right_count = 0;
        
        for (int j = 0; j < n; j++) {
            if (a[j] < target) {
                left_count++;
            } else if (a[j] > target) {
                right_count++;
            }
        }
        
        int current_calls = max(left_count, right_count);
        min_calls = min(min_calls, current_calls);
    }
    
    cout << min_calls << "\n";
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