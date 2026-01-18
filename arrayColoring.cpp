// You have 𝑛 cards arranged in a row. The 𝑖-th card has the integer 𝑎𝑖 written on it. All integers are distinct.

// You must color each card either red or blue such that the following conditions are satisfied:

// Any two adjacent cards in the row have different colors.
// If you rearrange the cards so that the numbers on them are in increasing order, any two adjacent cards in the new row must also have different colors.
// Determine if such a coloring exists.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1≤𝑡≤200). The description of the test cases follows.

// The first line of each test case contains a single integer 𝑛 (2≤𝑛≤100) — the length of the array.

// The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛).

// It is guaranteed that all elements of 𝑎 are distinct.

// Output
// For each test case, output "YES" if you can color the cards so that the conditions are satisfied, and "NO" otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int> >cards(n);
        for(int i=0;i<n;i++){
            cin>>cards[i].first;
            cards[i].second=i;
        }
        sort(cards.begin(),cards.end());
        bool first_card_is_synced = (cards[0].second % 2 == 0); 

        bool possible = true;
        for (int i = 0; i < n; i++) {
            bool current_card_is_synced = (cards[i].second % 2 == i % 2);
            
            if (current_card_is_synced != first_card_is_synced) {
                possible = false;
                break;
            }
        }
        if(possible){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
return 0;
}
