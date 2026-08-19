#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Boolean array to track which starting letters are available
    vector<bool> valid_starts(26, false);
    
    // Process the n initial words
    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        // Map 'a'-'z' to 0-25 by converting to uppercase first
        valid_starts[toupper(w[0]) - 'A'] = true;
    }
    
    bool possible = true;
    
    // Process the m abbreviations
    for (int i = 0; i < m; ++i) {
        string a;
        cin >> a;
        
        // If we already know it's impossible, we still need to read the 
        // rest of the input, but we don't need to keep checking chars.
        if (!possible) continue;
        
        for (char c : a) {
            if (!valid_starts[c - 'A']) {
                possible = false;
                break;
            }
        }
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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