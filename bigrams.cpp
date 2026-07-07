#include <iostream>
#include <vector>

void solve() {
    int k;
    std::cin >> k;
    
    int count_ge_3 = 0;
    int count_ge_2 = 0;
    
    for (int i = 0; i < k; ++i) {
        long long c;
        std::cin >> c;
        
        if (c >= 3) {
            count_ge_3++;
        }
        if (c >= 2) {
            count_ge_2++;
        }
    }
    
    // Logic check:
    // 1. Any single character appears 3 or more times (e.g., "aaa")
    // 2. At least two different characters appear 2 or more times (e.g., "abab")
    if (count_ge_3 >= 1 || count_ge_2 >= 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}