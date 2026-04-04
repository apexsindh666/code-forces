#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> rounds(n);
    map<string, int> finalScore;

    // Input + compute final scores
    for (int i = 0; i < n; i++) {
        cin >> rounds[i].first >> rounds[i].second;
        finalScore[rounds[i].first] += rounds[i].second;
    }

    // Find maximum score
    int maxScore = INT_MIN;
    for (auto &p : finalScore) {
        maxScore = max(maxScore, p.second);
    }

    // Second pass: track running scores
    map<string, int> currentScore;

    for (int i = 0; i < n; i++) {
        string name = rounds[i].first;
        int score = rounds[i].second;

        currentScore[name] += score;

        // Check winner condition
        if (currentScore[name] >= maxScore && finalScore[name] == maxScore) {
            cout << name << endl;
            break;
        }
    }

    return 0;
}