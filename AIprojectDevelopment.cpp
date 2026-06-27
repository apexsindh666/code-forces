#include <iostream>
#include <algorithm>

using namespace std;

// Helper function to perform ceiling division: ceil(A / B)
long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

void solve() {
    long long n, x, y, z;
    cin >> n >> x >> y >> z;

    // Strategy 1: Without using AI
    long long time_without_ai = ceil_div(n, x + y);

    // Strategy 2: Using AI
    long long time_with_ai = 0;
    // Check if Maxim finishes the project before or exactly when AI setup finishes
    if (ceil_div(n, x) <= z) {
        time_with_ai = ceil_div(n, x);
    } else {
        long long lines_done = x * z;
        long long lines_remaining = n - lines_done;
        long long new_speed = x + 10 * y;
        time_with_ai = z + ceil_div(lines_remaining, new_speed);
    }

    // Output the optimal (minimum) time
    cout << min(time_without_ai, time_with_ai) << "\n";
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