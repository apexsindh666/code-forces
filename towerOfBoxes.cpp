#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,m,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>d;
        int c=(d/m)+1;
        int res=(n+c-1)/c;
        cout<<res<<"\n";
    }
    return 0;
}