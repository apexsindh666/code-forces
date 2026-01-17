// Vadim's hourglass measures 𝑠 minutes. He flipped it over, and the time started. Every 𝑘 minutes, Vadim will flip his hourglass again. He will do this even if the sand is still falling. Also, if the sand has already finished falling but there are still some minutes left, Vadim will wait for the required time and only then flip the hourglass. Each flip is done instantly.

// However, Vadim needs to leave for errands in 𝑚 minutes, and he will stop flipping the hourglass (if Vadim needs to flip the hourglass in the last minute, he will do so). Determine how many minutes the sand will continue to fall after Vadim leaves.

// Input
// Each test consists of several test cases. The first line contains a single integer 𝑡 (1≤𝑡≤104) — the number of test cases. The following lines describe the test cases.

// In a single line of each test case, there are three integers 𝑠, 𝑘, and 𝑚 — the number of minutes the hourglass measures, the number of minutes after which the hourglass flips, and the number of minutes after which Vadim will leave for errands (1≤𝑠,𝑘,𝑚≤109).

// Output
// For each test case, output how many minutes the sand will continue to fall after Vadim leaves.

#include<iostream>
#include<algorithm>
using namespace std;
long long timeleft(long long s, long long k, long long m) {
    long long num_flips = m / k;
    long long rem_time = m % k;
    long long current_top;

    if (num_flips == 0) {
        current_top = s;
    } else if (num_flips % 2 == 1) {
        // Odd flips: 1, 3, 5...
        current_top = min(s, k);
    } else {
        // Even flips: 2, 4, 6...
        current_top = s;
    }

    return max(0LL, current_top - rem_time);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;
        cout << timeleft(s, k, m) << "\n";
    }
    return 0;
}