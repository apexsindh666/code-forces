#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << "YES\n";
        return;
    }
    int L_n = 0;
    int t = -1;
    for (int i = 0; i < 31; ++i) {
        if ((n >> i) & 1) {
            L_n = i + 1;
            if (t == -1) t = i; 
        }
    }
    int L = L_n + t;
    bool possible = true;
    for (int i = 0; i < L; ++i) {
        int bit_left = (n >> (L - 1 - i)) & 1;
        int bit_right = (n >> i) & 1;
        if (bit_left != bit_right) {
            possible = false;
            break;
        }
    }
    if (L % 2 == 1) {
        int mid_bit = (n >> (L / 2)) & 1;
        if (mid_bit != 0) {
            possible = false;
        }
    }

    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}