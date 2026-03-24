#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Set of alcoholic drinks
    set<string> alcohol = {
        "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE",
        "GIN", "RUM", "SAKE", "TEQUILA",
        "VODKA", "WHISKEY", "WINE"
    };
    
    int count = 0;
    
    while (n--) {
        string s;
        cin >> s;
        
        // Check if it's a number (age)
        if (isdigit(s[0])) {
            int age = stoi(s);
            if (age < 18) {
                count++;
            }
        } 
        else {
            // It's a drink
            if (alcohol.count(s)) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}