#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Standard competitive programming optimization for I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> s(4);
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }

    // Sorting O(N log N) makes checking combinations much easier
    sort(s.begin(), s.end());

    // Case 1: Non-degenerate Triangle (Sum of two smaller sides > largest side)
    // We only need to check adjacent triples in a sorted array
    if ((s[0] + s[1] > s[2]) || (s[1] + s[2] > s[3])) {
        cout << "TRIANGLE" << endl;
    } 
    // Case 2: Degenerate Triangle (Sum of two smaller sides == largest side)
    else if ((s[0] + s[1] == s[2]) || (s[1] + s[2] == s[3])) {
        cout << "SEGMENT" << endl;
    } 
    // Case 3: No structure possible
    else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}