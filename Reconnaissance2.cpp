#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    
    int minDiff=INT_MAX, idx1=0, idx2=1;
    for(int i=0;i<n;i++){
        int j=(i+1)%n;
        int diff=abs(a[i]-a[j]);
        if(diff<minDiff){
            minDiff=diff;
            idx1=i+1;
            idx2=j+1;
        }
    }
    cout<<idx1<<" "<<idx2<<endl;
}