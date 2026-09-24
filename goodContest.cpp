#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    
    // The maximum number of people who solved all three problems
    int all_solved = min({a1, a2, a3});
    
    // The remaining participants are weak
    int weak_participants = n - all_solved;
    
    cout << weak_participants << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}