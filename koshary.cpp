#include<iostream>
using namespace std;
void solve(){
    int x,y;
    cin>>x>>y;
    int oc=0;
    if(x%2!=0){
        oc+=1;
    }
    if(y%2!=0){
        oc+=1;
    }
    if(oc<=1){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    while(n>0){
        solve();
        n-=1;
    }
    return 0;
}