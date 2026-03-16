#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long long A;
    cin >> A;

    long long total_sum = 0;
    long long num_bases = A - 2;

    for (long long base = 2; base <= A - 1; base++) {
        long long temp = A;

        while (temp > 0) {
            total_sum += temp % base;
            temp /= base;
        }
    }

    long long g = gcd(total_sum, num_bases);

    cout << total_sum / g << "/" << num_bases / g << endl;

    return 0;
}