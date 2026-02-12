#include <iostream>

using namespace std;

// Helper function to calculate sum of digits
int sumOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    long long x;
    cin >> x;

    // Based on our logic, y - d(y) must be a multiple of 9
    if (x % 9 != 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 0;
    /* Since y = x + d(y) and the max digit sum for x up to 10^9 
       is relatively small (e.g., d(999,999,999) = 81), 
       we only need to check a small range above x.
    */
    for (long long y = x; y <= x + 100; y++) {
        if (y - sumOfDigits(y) == x) {
            count++;
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O for competitive programming standards
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}