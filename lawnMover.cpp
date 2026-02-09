#include <iostream>
using namespace std;

long long maxb(long long n, long long w) {
    return n - (n / w);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, w;
        cin >> n >> w;
        cout << maxb(n, w) << "\n";
    }
    return 0;
}