#include<iostream>
#include<set>
using namespace std;
void solve(){
    int n,val;
    cin>>n;
    set<int>a;
    for(int i=0;i<n;i++){
        cin>>val;
        a.insert(val);
    }
    int k=a.size();
    cout<<(2*k)-1<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    solve();
    }
    return 0;
}