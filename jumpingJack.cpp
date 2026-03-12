#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
    n = abs(n); 
    long long k = 0;   
    long long sum = 0; 
    while (sum < n || (sum - n) % 2 != 0) {
        k++;
        sum += k;
    }
    cout << k << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    if (cin >> x) {
        solve(x);
    }
    return 0;
}