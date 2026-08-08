#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> st;
    for (int i = 0; i < n; ++i) {
        long long curr = a[i];
        while (!st.empty() && st.back() > curr) {
            long long prev = st.back();
            st.pop_back();
            curr = prev + curr;
        }
        st.push_back(curr);
    }

    long long max_pile = 0;
    for (long long val : st) {
        max_pile = max(max_pile, val);
    }

    cout << max_pile << "\n";
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