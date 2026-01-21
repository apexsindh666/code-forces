#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
            }
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        int max_streak=1,current_streak=1;
        for(int k=1;k<a.size();k++){
            if(a[k]==a[k-1]+1)current_streak++;
            else{
                max_streak=max(max_streak,current_streak);
                current_streak=1;
            }
        }
        max_streak=max(max_streak,current_streak);
        cout<<max_streak<<endl;
    }

    return 0;
}