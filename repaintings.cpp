#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Logic:
 * 1. A square (i, j) is "initially black" if (i % 2 == j % 2).
 * 2. For a square to be repainted x times, it must have a padding of x on all sides.
 * 3. Squares surviving at least x times are in a rectangle of size:
 * H = n - 2*(x-1), W = m - 2*(x-1).
 * Wait, simpler: the rectangle is [x, n-x+1] by [x, m-x+1].
 * 4. The number of "valid" squares in an H x W rectangle starting with (odd, odd) is:
 * ceil(H/2)*ceil(W/2) + floor(H/2)*floor(W/2).
 */

long long countValid(long long h, long long w) {
    if (h <= 0 || w <= 0) return 0;
    long long ce_h = (h + 1) / 2;
    long long fl_h = h / 2;
    long long ce_w = (w + 1) / 2;
    long long fl_w = w / 2;
    
    return (ce_h * ce_w) + (fl_h * fl_w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, x;
    if (!(cin >> n >> m >> x)) return 0;

    // Rectangle dimensions for squares painted AT LEAST x times
    long long h_x = n - 2 * (x - 1);
    long long w_x = m - 2 * (x - 1);

    // Rectangle dimensions for squares painted AT LEAST x + 1 times
    long long h_next = n - 2 * x;
    long long w_next = m - 2 * x;

    long long at_least_x = countValid(h_x, w_x);
    long long at_least_x_plus_1 = countValid(h_next, w_next);

    cout << at_least_x - at_least_x_plus_1 << endl;

    return 0;
}