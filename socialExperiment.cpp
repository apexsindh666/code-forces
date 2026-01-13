#include<iostream>
using namespace std;
// int socioexp(int n) {
//     if (n <= 3) return n; // Handles 2 and 3
//     return n % 2;         // Returns 0 for even, 1 for odd
// }
int socioexp(int n){
    int s;
    if(n==2){
        s=2;
    }else if(n==3){
        s=3;
    }else if(n%2==0 &&n>=4){
        s=0;
    }else if(n%2==1 &&n>=5){
        s=1;
    }
return s;
}
int main(){
int t,n,s;
cin>>t;
for(int i=0;i<t;i++){
    cin>>n;
    s=socioexp(n);
    cout<<s<<endl;
}
    return 0;
}