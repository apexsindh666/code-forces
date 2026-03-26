#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,n,c,k;
    cin>>t;
    while(t--){
        cin>>n>>c>>k;
        vector<long long >a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
        if (a[i] <= c) {
            long long can_add = min(k, c - a[i]);
            c += (a[i] + can_add);
            k -= can_add;
        } else {
            break; 
        }
    }
    cout<<c<<"\n";
    }
    return 0;
}