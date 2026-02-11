#include<iostream>
using namespace std;
int config(int n){
    if(n%2!=0){
        return 0;
    }else{
        return (n/4)+1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int res=config(n);
        cout<<res<<"\n";
    }
    return 0;
}