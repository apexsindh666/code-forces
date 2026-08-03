#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    string max_result = "";
    int n = s.length();

    // Alice tries deleting every possible '0'
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            // Alice deletes s[i]
            string s_prime = s.substr(0, i) + s.substr(i + 1);
            
            // Bob deletes the first '1' in s_prime
            size_t first_one = s_prime.find('1');
            string final_str = s_prime.substr(0, first_one) + s_prime.substr(first_one + 1);
            
            // Alice wants the lexicographically largest outcome
            if (max_result.empty() || final_str > max_result) {
                max_result = final_str;
            }
        }
    }

    cout << max_result << "\n";
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