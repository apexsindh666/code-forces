#include<iostream>
using namespace std;
int main(){
int n,h;
cin>>n>>h;
int sum=0,x;
for(int i=0;i<n;i++){
    cin>>x;
    if(x<=h){
        sum+=1;
    }else{
        sum+=2;
    }
}
cout<<sum<<endl;
    return 0;
}