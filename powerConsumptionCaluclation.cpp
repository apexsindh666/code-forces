#include <iostream>
using namespace std;

long long CalculatePower() {
    int n;
    long long P1, P2, P3, T1, T2;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

    long long total_power = 0;
    long long previous_r = -1;

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        total_power += (r - l) * P1;
        if (previous_r != -1) {
            long long t = l - previous_r;

            if (t <= T1) {
                total_power += t * P1;
            } else if (t <= T1 + T2) {
                total_power += (T1 * P1) + ((t - T1) * P2);
            } else {
                total_power += (T1 * P1) + (T2 * P2) + ((t - T1 - T2) * P3);
            }
        }

        previous_r = r;
    }

    return total_power;
}

int main() {
    cout << CalculatePower() << endl;
    return 0;
}