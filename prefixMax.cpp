#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        int s = *max_element(a.begin(), a.end());
        int res=s*n;
        cout<<res<<endl;
    }
    return 0;
}