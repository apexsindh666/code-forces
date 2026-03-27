#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // store original index (1-based)
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int target = a[i].first;
        int left = 0, right = n - 1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }

            int sum = a[left].first + a[right].first;

            if (sum == target) {
                cout << a[i].second << " "
                     << a[left].second << " "
                     << a[right].second << endl;
                return 0;
            }
            else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}