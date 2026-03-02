// FUNCTION solve():
//     READ n
//     READ string s
    
//     SET max_blocks = 0
    
//     // Try every possible rotation point i
//     FOR i FROM 0 TO n-1:
//         // Create the rotated string
//         SET rotated_s = s[i...n-1] + s[0...i-1]
        
//         // Count blocks in rotated_s
//         SET current_blocks = 1
//         FOR j FROM 1 TO n-1:
//             IF rotated_s[j] != rotated_s[j-1]:
//                 current_blocks = current_blocks + 1
        
//         IF current_blocks > max_blocks:
//             max_blocks = current_blocks
            
//     PRINT max_blocks
#include<iostream>
#include<string>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max_blocks = 0;
    string doubled = s + s; 
    for (int i = 0; i < n; i++) {
        string rotated = doubled.substr(i, n); 
        
        int current_blocks = 1;
        for (int j = 1; j < n; j++) {
            if (rotated[j] != rotated[j - 1]) {
                current_blocks++;
            }
        }
        
        if (current_blocks > max_blocks) {
            max_blocks = current_blocks;
        }
    }
    cout << max_blocks << "\n"; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}