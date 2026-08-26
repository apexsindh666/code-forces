#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Strip {
    long long x_end;      // Right endpoint of this x-interval
    long long width;      // x_end - x_start
    long long height;     // Height of the strip
    long long area;       // width * height
};

void solve() {
    long long S;
    int q;
    if (!(cin >> S >> q)) return;

    // 1. Find all divisors of S
    vector<long long> divisors;
    for (long long i = 1; i * i <= S; ++i) {
        if (S % i == 0) {
            divisors.push_back(i);
            if (i * i != S) {
                divisors.push_back(S / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    // 2. Build non-overlapping vertical strips covering the union
    // For x in (divisors[i-1], divisors[i]], max height is S / divisors[i]
    int k = divisors.size();
    vector<Strip> strips(k);
    vector<long long> pref_area(k + 1, 0);
    vector<long long> pref_width(k + 1, 0);
    vector<long long> heights(k);

    long long prev_x = 0;
    for (int i = 0; i < k; ++i) {
        strips[i].x_end = divisors[i];
        strips[i].width = divisors[i] - prev_x;
        strips[i].height = S / divisors[i];
        strips[i].area = strips[i].width * strips[i].height;
        heights[i] = strips[i].height;

        pref_area[i + 1] = pref_area[i] + strips[i].area;
        pref_width[i + 1] = pref_width[i] + strips[i].width;
        prev_x = divisors[i];
    }

    // 3. Process each query (x, y)
    while (q--) {
        long long qx, qy;
        cin >> qx >> qy;

        // Find the strip containing qx (or capping at qx)
        // strips[i].x_end >= qx
        auto it_x = lower_bound(divisors.begin(), divisors.end(), qx);
        int idx_x = it_x - divisors.begin(); // 0-indexed strip index containing qx
        if (idx_x >= k) idx_x = k - 1;

        // Effective x within the region
        long long effective_x = min(qx, divisors.back());

        // Heights are strictly decreasing: heights[0] > heights[1] > ... > heights[k-1]
        // We find the first strip where height <= qy
        // Using reverse iterator or custom comparator
        auto it_y = lower_bound(heights.begin(), heights.end(), qy, greater<long long>());
        int idx_y = it_y - heights.begin(); // Strips 0 .. idx_y - 1 have height > qy

        long long total_area = 0;

        if (idx_x < idx_y) {
            // All strips up to idx_x have height >= qy
            // So height is capped at qy for the entire interval [0, effective_x]
            total_area = effective_x * qy;
        } else {
            // For strips 0 .. idx_y - 1: height is capped at qy
            long long width_tall = (idx_y > 0 ? pref_width[idx_y] : 0);
            total_area += width_tall * qy;

            // For strips idx_y .. idx_x - 1: fully within the region, height <= qy
            if (idx_x > idx_y) {
                total_area += (pref_area[idx_x] - pref_area[idx_y]);
            }

            // For the partial strip idx_x:
            long long start_x = (idx_x > 0 ? divisors[idx_x - 1] : 0);
            long long cur_w = max(0LL, effective_x - start_x);
            long long cur_h = min(qy, strips[idx_x].height);
            total_area += cur_w * cur_h;
        }

        cout << total_area << "\n";
    }
}

int main() {
    // Fast I/O
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