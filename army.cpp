// Function solve():
//     Read n
//     Read array d of size n-1
//     Read a, b
    
//     totalYears = 0
//     // Loop from the starting rank index to the target rank index
//     For i from a to b-1:
//         totalYears += d[i-1] // i-1 because array d starts at d[0] for rank 1->2
        
//     Print totalYears
#include<iostream>
using namespace std;
void solve(){
    int n,a,b;
    cin>>n;
    int d[n-1];
    for(int i=0;i<n-1;i++){
        cin>>d[i];
    }
    cin>>a>>b;
    int totalyears=0;
    for(int i=a;i<b;i++){
        totalyears+=d[i-1];
    }
    cout<<totalyears<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}