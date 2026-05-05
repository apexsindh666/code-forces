#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long min_val = 1e18; // Use a large initial value for LLONG_MAX

void solve(vector<long long> nums, int op_idx, const vector<char>& ops) {
    if (nums.size() == 1) {
        min_val = min(min_val, nums[0]);
        return;
    }

    // Try picking every possible pair of numbers
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            vector<long long> next_nums;
            
            // Add all numbers EXCEPT the two we picked
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) next_nums.push_back(nums[k]);
            }

            // Apply the operation and add the result to the new list
            long long res;
            if (ops[op_idx] == '+') res = nums[i] + nums[j];
            else res = nums[i] * nums[j];
            
            next_nums.push_back(res);

            // Recurse to the next operation
            solve(next_nums, op_idx + 1, ops);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> a(4);
    vector<char> ops(3);

    for (int i = 0; i < 4; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> ops[i];

    solve(a, 0, ops);

    cout << min_val << endl;

    return 0;
}