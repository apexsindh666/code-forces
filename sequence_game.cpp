#include<iostream>
using namespace std;
int main(){
    int m,n,x;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        int arr[n];
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            ma=max(arr[i],ma);
            mi=min(arr[i],mi);
        }
            cin>>x;
            if(x>=mi&&x<=ma){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        
    }
    return 0;
}