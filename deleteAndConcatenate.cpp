#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n;
    long long c;
    if (!(cin >> n >> c)) return;
 
    vector<long long> a(n);
    vector<long long> b(n);
    long long base_score = 0;
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        base_score += (a[i] - c);
        b[i] = c - a[i];
    }
 
    // Sort b in descending order to greedily pick the largest gains
    sort(b.begin(), b.end(), greater<long long>());
 
    int max_pairs = n / 2;
    long long max_gain = 0;
 
    for (int i = 0; i < max_pairs; ++i) {
        if (b[i] > 0) {
            max_gain += b[i];
        } else {
            break; // No further positive gains possible
        }
    }
 
    cout << base_score + max_gain << "\n";
}
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
 
    return 0;
}