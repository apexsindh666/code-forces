#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Using 1-indexed array for a
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Difference array to mark forbidden ranges in [0, n - 1]
    // Size is n + 2 to safely handle updates up to index n
    vector<int> diff(n + 2, 0);

    for (int k = 1; k <= n; ++k) {
        // Use long long to prevent integer overflow (since a[k] * k can be up to 10^10)
        long long L = a[k] * k;
        long long R = (a[k] + 1) * k - 1;

        // We only care about forbidden indices strictly less than n
        if (L < n) {
            long long clamped_R = min(R, (long long)n - 1);
            diff[L] += 1;
            diff[clamped_R + 1] -= 1;
        }
    }

    // Reconstruct the set B using running prefix sum
    vector<int> B;
    int current_forbidden_count = 0;
    
    for (int i = 0; i < n; ++i) {
        current_forbidden_count += diff[i];
        
        // If current index is not covered by any forbidden range, include it in B
        if (current_forbidden_count == 0) {
            B.push_back(i);
        }
    }

    // Output the size and elements of B
    cout << B.size() << "\n";
    for (size_t i = 0; i < B.size(); ++i) {
        cout << B[i] << (i + 1 == B.size() ? "" : " ");
    }
    cout << "\n";
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