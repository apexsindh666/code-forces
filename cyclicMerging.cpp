#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long max_val = -1;
    int max_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
    }

    // Treat the ring as a line by starting from the max element
    vector<long long> b;
    for (int i = 0; i < n; i++) {
        b.push_back(a[(max_idx + i) % n]);
    }

    // O(N) Greedy Observation: Each element except the absolute max 
    // is merged with the smaller of its two nearest larger neighbors.
    // In this specific problem, it simplifies to:
    // Total Cost = Sum of all elements except the absolute max +
    // extra costs from internal 'peaks'.
    
    // Actually, for this specific problem, the sum of all elements 
    // excluding one occurrence of the maximum is the baseline. 
    // BUT every time a smaller element is 'trapped' between two larger ones, 
    // it contributes to the cost.

    long long total_cost = 0;
    // Standard Monotonic Stack to find NGN
    stack<long long> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() < b[i]) {
            // The element s.top() is being 'merged'
            // The cost is the minimum of its neighbors. 
            // b[i] is the right neighbor. 
            // The new s.top() (after popping) would be the left neighbor.
            long long middle = s.top();
            s.pop();
            if (!s.empty()) {
                total_cost += min(s.top(), b[i]);
            } else {
                total_cost += b[i];
            }
        }
        s.push(b[i]);
    }

    // Any remaining elements in the stack (decreasing order)
    while (s.size() > 1) {
        long long val = s.top();
        s.pop();
        total_cost += s.top();
    }

    cout << total_cost << "\n";
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