#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip> // Necessary for setprecision

using namespace std;

void solveEquation(long double a, long double b, long double c) {
    // Set global precision for all outputs
    cout << fixed << setprecision(10);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << -1 << "\n";
            else cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
            cout << -c / b << "\n";
        }
    } else {
        long double d = (b * b) - (4 * a * c);
        if (d < -1e-11) { 
            cout << 0 << "\n";
        } else if (abs(d) <= 1e-11) {
            cout << 1 << "\n";
            cout << -b / (2 * a) << "\n";
        } else {
            cout << 2 << "\n";
            long double root1 = (-b - sqrt(d)) / (2 * a);
            long double root2 = (-b + sqrt(d)) / (2 * a);
            if (root1 > root2) swap(root1, root2);
            cout << root1 << "\n" << root2 << "\n";
        }
    }
}

int main() {
    long double a, b, c;
    if (cin >> a >> b >> c) {
        solveEquation(a, b, c);
    }
    return 0;
}