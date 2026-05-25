#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Stores the current sorted rank of each suffix
int rank_pos[1005];

// Wrapper for the interactive query
string query(int i, int j) {
    cout << "query " << i << " " << j << "\n";
    cout.flush();
    string res;
    cin >> res;
    return res;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> A;
    A.push_back(n);

    // Initialize ranks. rank_pos[n+1] represents the empty suffix (always smallest)
    for (int i = 0; i <= n + 1; ++i) {
        rank_pos[i] = -1;
    }
    rank_pos[n] = 0;

    // Insert suffixes from shortest to longest
    for (int k = 1; k < n; ++k) {
        int curr = n - k;
        int target_rank = rank_pos[curr + 1];

        // Step 1: Find splitting positions (boundaries between different first characters)
        vector<pair<int, int>> blocks;
        int start = 0;
        for (int i = 0; i < k - 1; ++i) {
            // Inversion in remainder ranks implies a different first character
            if (rank_pos[A[i] + 1] > rank_pos[A[i+1] + 1]) {
                blocks.push_back({start, i});
                start = i + 1;
            }
        }
        blocks.push_back({start, k - 1});

        // Step 2: Collect representatives
        vector<int> Y;
        Y.push_back(-1); // Always include the beginning boundary

        for (auto& block : blocks) {
            int L = block.first, R = block.second;
            int y = L - 1;
            
            // Binary search the exact insertion point inside this block
            int sL = L, sR = R;
            while (sL <= sR) {
                int mid = sL + (sR - sL) / 2;
                if (rank_pos[A[mid] + 1] < target_rank) {
                    y = mid;
                    sL = mid + 1;
                } else {
                    sR = mid - 1;
                }
            }
            Y.push_back(y);
        }

        // Clean duplicates to ensure pure O(log 26) search
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());

        // Step 3: Fast Binary Search over representatives
        int L = 1, R = Y.size() - 1;
        int best_idx = 0;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            int c = Y[mid];
            string res = query(A[c], curr);
            if (res == "first") {
                best_idx = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }

        int c = Y[best_idx];
        int next_c = c + 1;
        bool is_less = false;

        // Step 4: Verify exact fit
        if (next_c == k) {
            is_less = true;
        } else {
            string res = query(curr, A[next_c]);
            is_less = (res == "first");
        }

        if (is_less) {
            // Fast path: Fit perfectly!
            A.insert(A.begin() + next_c, curr);
        } else {
            // Step 5: Fallback path (Triggered at most 25 times globally)
            // A new first character was discovered; narrow down the search range.
            int search_L = next_c + 1;
            int search_R = (best_idx + 1 < Y.size()) ? Y[best_idx + 1] - 1 : k - 1;

            int insert_pos = search_R + 1;
            int sL = search_L, sR = search_R;
            while (sL <= sR) {
                int mid = sL + (sR - sL) / 2;
                string res = query(curr, A[mid]);
                if (res == "first") {
                    insert_pos = mid;
                    sR = mid - 1;
                } else {
                    sL = mid + 1;
                }
            }
            A.insert(A.begin() + insert_pos, curr);
        }

        // Update the rank mapping for the next suffix iteration
        for (int i = 0; i < A.size(); ++i) {
            rank_pos[A[i]] = i;
        }
    }

    // Step 6: Print final ordering
    cout << "answer";
    for (int i = 0; i < n; ++i) {
        cout << " " << A[i];
    }
    cout << "\n";
    cout.flush();

    return 0;
}