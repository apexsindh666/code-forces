#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using a struct to keep data organized
struct House {
    double left, right;
};

// Custom comparator to sort houses by their position on the X-axis
bool compareHouses(const House& a, const House& b) {
    return a.left < b.left;
}

void solve() {
    int n;
    double t;
    if (!(cin >> n >> t)) return;

    vector<House> houses(n);
    for (int i = 0; i < n; i++) {
        double x, a;
        cin >> x >> a;
        houses[i].left = x - a / 2.0;
        houses[i].right = x + a / 2.0;
    }

    // O(N log N) Sorting
    sort(houses.begin(), houses.end(), compareHouses);

    // We start with 2 because we can always place one 
    // at the very beginning and one at the very end.
    int count = 2;

    for (int i = 0; i < n - 1; i++) {
        double gap = houses[i+1].left - houses[i].right;

        if (gap > t) {
            count += 2; // Can touch left house OR right house
        } else if (abs(gap - t) < 1e-9) { // Using epsilon for double comparison
            count += 1; // Fits exactly, touches both
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}