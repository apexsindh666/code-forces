#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n, a;
    if (!(cin >> n >> a)) return;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // Marbles strictly less than a
    int countLeft = lower_bound(v.begin(), v.end(), a) - v.begin();
    
    // Marbles strictly greater than a
    int countRight = v.end() - upper_bound(v.begin(), v.end(), a);

    if (countLeft == 0 && countRight == 0) {
        // Alice has everything or no marbles are winnable
        cout << 1337 << endl; 
    } 
    else if (countLeft >= countRight) {
        // Bob wins more by taking the left side.
        // He picks b to be the largest marble that is less than a.
        // Standing exactly on the marble makes his distance 0.
        int target_idx = lower_bound(v.begin(), v.end(), a) - v.begin() - 1;
        cout << v[target_idx] << endl;
    } 
    else {
        // Bob wins more by taking the right side.
        // He picks b to be the smallest marble that is greater than a.
        int target_idx = upper_bound(v.begin(), v.end(), a) - v.begin();
        cout << v[target_idx] << endl;
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