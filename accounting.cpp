#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem: A. Accounting
 * Fixed Logic: Prevents Signed Integer Overflow for Test #26.
 * We use a "break" if the power grows beyond the possible range of Y.
 */

int main() {
    // Optimize I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, n;
    if (!(cin >> A >> B >> n)) return 0;

    // Case 1: A is zero
    if (A == 0) {
        if (B == 0) {
            cout << 1 << endl; // Any X works, returning 1
        } else {
            cout << "No solution" << endl;
        }
        return 0;
    }

    // Case 2: Integer Divisibility Check
    // If B is not divisible by A, no integer X can satisfy A * X^n = B
    if (B % A != 0) {
        cout << "No solution" << endl;
        return 0;
    }

    int Y = B / A;

    // Case 3: Brute Force Search for X in range [-1000, 1000]
    for (int x = -1000; x <= 1000; ++x) {
        long long current_power = 1;
        bool overflowed = false;

        for (int i = 0; i < n; ++i) {
            current_power *= x;

            // CIRCUIT BREAKER: If current_power exceeds 1000, 
            // it can't be Y (unless n is small, but the loop handles that).
            // We use 1000000 as a safe buffer to prevent long long overflow.
            if (abs(current_power) > 2000) { 
                overflowed = true;
                break; 
            }
        }

        if (!overflowed && current_power == Y) {
            cout << x << endl;
            return 0;
        }
    }

    cout << "No solution" << endl;
    return 0;
}