#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto& x : a) cin >> x;
        
        bool hasBreak = false;
        for (int i = 0; i + 1 < m; i++) {
            if (a[i + 1] != a[i] + 1) {
                hasBreak = true;
                break;
            }
        }
        
        cout << (hasBreak ? 1 : n - a[m - 1] + 1) << "\n";
    }
    return 0;
}