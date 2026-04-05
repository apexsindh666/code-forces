#include<iostream>
#include<vector>
using namespace std;
int almostprime(int n){
    int aptotal=0;
    vector<int>a(n+1,0);
    for(int i=2;i<=n;i++){
        if(a[i]==0){
            for(int j=2*i;j<=n;j+=i){
                a[j]+=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==2){
            aptotal+=1;
        }
    }
    return aptotal;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int res=almostprime(n);
    cout<<res<<"\n";
    return 0;
}