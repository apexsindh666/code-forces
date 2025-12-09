#include<iostream>
using namespace std;
int bin(int n){
    int num=0;
    while(n>0){
        int rem=n%2;
        if(rem==1){
            num++;
        }
        n/=2;
    }
    return num;
}
int main(){
int n;
cin>>n;
int s=bin(n);
cout<<s<<endl;
    return 0;
}