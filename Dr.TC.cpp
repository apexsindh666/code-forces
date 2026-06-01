#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Count the number of '1's in the original string
    long long c = count(s.begin(), s.end(), '1');
    
    // Apply the mathematical formula
    // Using long long prevents potential overflow issues in larger bounds, 
    // though for n <= 10 it fits easily in standard int.
    long long total_ones = (n * c) + n - (2 * c);
    
    cout << total_ones << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}