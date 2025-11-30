#include<iostream>
using namespace std;
int main(){
int n,b,d;
cin>>n>>b>>d;
int c=0;
int arr[n];
int sum=0;
for(int i=0;i<n;i++){
    cin>>arr[i];
    if(arr[i]<=b){
        sum+=arr[i];
        if(sum>d){
            c++;
            sum=0;
        }
    }
}
cout<<c<<endl;
    return 0;
}