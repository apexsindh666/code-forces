// Function solve():
//     Read n
//     If n is divisible by 3:
//         Print 0
//     Else:
//         Print 3 - (n % 3)

// Main():
//     Read t (number of test cases)
//     While t is greater than 0:
//         Call solve()
//         Decrement t

#include<iostream>
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n%3==0){
        cout<<0<<"\n";
    }else{
        cout<<3-(n%3)<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}