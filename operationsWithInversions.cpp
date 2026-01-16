#include<iostream>
#include<vector>
using namespace std;
int op(vector<int>&a){
    int n=a.size();
    int current_max=a[0];
    int r=0;
    for(int i=1;i<n;i++){
        if(a[i]<current_max){
            r++;
        }else {
            current_max=a[i];
        }
    }
    return r;
}
int main(){
int t,n;
cin>>t;
for(int i=0;i<t;i++){
    cin>>n;
    vector<int>a(n);
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    cout<<op(a)<<endl;
}
    return 0;
}