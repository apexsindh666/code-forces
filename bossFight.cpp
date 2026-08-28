#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> freq;
    long long total_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        total_sum += a[i];
    }
    
    int max_val = a[0];
    int max_count = 0;
    for (const auto& [val, count] : freq) {
        if (count > max_count) {
            max_count = count;
            max_val = val;
        }
    }
    
    int other_cards = n - max_count;
    
    if (max_count <= other_cards + 1) {
        cout << total_sum << "\n";
    } else {
        long long sum_others = total_sum - 1LL * max_count * max_val;
        long long ans = sum_others + 1LL * (other_cards + 2) * max_val;
        cout << ans << "\n";
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