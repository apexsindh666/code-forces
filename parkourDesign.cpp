#include<iostream>
using namespace std;
int pd(long long x, long long y) {
    long long diff = x - 2 * y;
    if (diff % 3 != 0) return 0; 

    long long k = diff / 3;
    if (x >= 2 * y && x >= -4 * y && y + (k / 2) >= 0) {
        return 1; 
    }

    return 0; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int res=pd(x,y);
        if(res==1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}