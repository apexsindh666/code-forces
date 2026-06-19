#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int query_count = 0;

// Helper function to interact with the grader
int ask(int p, int e) {
    cout << "? " << p << " " << e << endl;
    query_count++;
    int response;
    cin >> response;
    if (response == -1) {
        exit(0); // Exceeded queries or invalid move
    }
    return response;
}

void solve() {
    int m;
    if (!(cin >> m)) return;

    query_count = 0;
    // G[i] stores the query ID representing the state of graph G_i
    vector<int> G(15, 0); 
    vector<int> bracket(m + 1, 15);
    vector<int> ans(m + 1, -1);

    // Pass 1: Determine the bracket of every edge
    for (int e = 1; e <= m; ++e) {
        int low = 0, high = 14, res_bracket = 15;
        int last_valid_qId = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int qId = query_count + 1;
            int status = ask(G[mid], e);

            if (status == 1) {
                res_bracket = mid;
                last_valid_qId = qId; // Reuse this query ID for updating G[mid]
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        bracket[e] = res_bracket;
        if (res_bracket <= 14) {
            G[res_bracket] = last_valid_qId; // Dynamic update without extra queries
        }
    }

    // Pass 2: Determine bridge / cycle length
    for (int e = 1; e <= m; ++e) {
        int b = bracket[e];
        if (b >= 14) {
            // Check if it is a bridge or on a big cycle
            int status = ask(0, e);
            if (status == 0) {
                ans[e] = -1; // Bridge
            } else {
                ans[e] = 0;  // Big cycle
            }
        } else {
            // Binary search the cycle length in range [b + 1, 14]
            int low = b + 1, high = 14, L = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int status = ask(G[mid], e);
                if (status == 1) {
                    L = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans[e] = L; // If L remains 0, it means it's a big cycle (> 14)
        }
    }

    // Output the final classifications
    cout << "!";
    for (int e = 1; e <= m; ++e) {
        cout << " " << ans[e];
    }
    cout << endl;

    int correct;
    cin >> correct;
    if (correct == -1) {
        exit(0);
    }
}

int main() {
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