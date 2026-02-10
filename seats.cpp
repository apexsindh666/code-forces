#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // First, identify spots that are already occupied or "blocked" by adjacency
    vector<bool> blocked(n, false);
    int initial_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            initial_count++;
            blocked[i] = true;
            if (i > 0) blocked[i - 1] = true;
            if (i < n - 1) blocked[i + 1] = true;
        }
    }

    int added_students = 0;
    for (int i = 0; i < n; i++) {
        // If this seat is not blocked, a student COULD sit here.
        // To minimize, we only place a student if it's necessary to block a gap.
        if (!blocked[i]) {
            // Greedy Rule: Place a student at the furthest possible spot that 
            // covers the current seat 'i'. That spot is i + 1.
            // If i+1 is out of bounds or would be adjacent to a '1', we use i.
            
            int place_at = i;
            if (i + 1 < n && (i + 2 >= n || s[i + 2] != '1')) {
                // If i+1 is safe from a right-side '1', placing here blocks i, i+1, i+2
                place_at = i + 1;
            }

            added_students++;
            // Mark the new student's influence
            blocked[place_at] = true;
            if (place_at > 0) blocked[place_at - 1] = true;
            if (place_at < n - 1) blocked[place_at + 1] = true;
        }
    }

    cout << initial_count + added_students << "\n";
}

int main() {
    // Fast I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}