#include <iostream>
#include <vector>
#include <numeric>  
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> winners_found(n, false);

    for(int start_player = 0; start_player < n; start_player++) {
        
        vector<int> current_dishes = a;  
        int total_dishes = accumulate(a.begin(), a.end(), 0);
        int current_turn = start_player;

        while(total_dishes > 0) {
            if(current_dishes[current_turn] > 0) {
                current_dishes[current_turn]--;
                total_dishes--;

                if(total_dishes == 0) {
                    winners_found[current_turn] = true;
                    break;
                }
            }

            current_turn = (current_turn + 1) % n;
        }
    }

    int count = 0;
    for(bool win : winners_found) {
        if(win) count++;
    }

    cout << count << endl;
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}