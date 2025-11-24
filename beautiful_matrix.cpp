#include<iostream>
using namespace std;
int main(){
    int n=5;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int p,q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                p=i;
                q=j;
            }
        }
    }
    int s;
    s=abs(p-2)+abs(q-2);
    cout<<s<<endl;
return 0;
}