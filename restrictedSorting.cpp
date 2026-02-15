#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For abs()

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> s = a; 
        sort(s.begin(), s.end());

        if (a == s) {
            cout << -1 << "\n";
        } else {
            // Initialize res to a very large value for EACH test case
            int res = 1e9 + 7; 
            int v_min = s[0];
            int v_max = s[n-1];

            for (int i = 0; i < n; i++) {
                if (a[i] != s[i]) {
                    // Logic: The bottleneck k is the minimum of these maximum distances
                    int dist_to_min = abs(a[i] - v_min);
                    int dist_to_max = abs(a[i] - v_max);
                    res = min(res, max(dist_to_min, dist_to_max));
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}