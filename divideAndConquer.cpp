#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,y;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;
        if(x%y==0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
return 0;
}