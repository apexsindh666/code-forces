#include<iostream>
#include<numeric>
using namespace std;
void price(int l,int a,int b){
int g=std::gcd(l,b);
int s=a+g*((l-1-a)/g);
cout<<s<<endl;
}
int main(){
int n,l,a,b;
cin>>n;
for(int i=0;i<n;i++){
    cin>>l>>a>>b;
    price(l,a,b);
}
    return 0;
}