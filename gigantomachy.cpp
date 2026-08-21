#include<iostream>
using namespace std;
void solve(){
    long long t,n,m;
    cin>>t;
    while(t>0){
        cin>>n>>m;
        long long a[n],b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        long long total_hits_Bea = a[0] + (n - 1);
        long long total_hits_Ver = b[0] + (m - 1);
        if (total_hits_Ver <= total_hits_Bea){
            cout<<1<<"\n";
        }else{
            cout<<2<<"\n";
        }
        t = t - 1;
    }
}
int main(){
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}