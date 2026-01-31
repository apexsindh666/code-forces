#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,s,x;
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n>>s>>x;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<a.size();i++){
            sum+=a[i];
        }
        if (sum > s) {
            cout << "NO" << "\n";
        } else if ((s - sum) % x == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}