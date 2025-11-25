#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b,c=0,m=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        c=(c-a)+b;
        m=max(m,c);
    }
    cout<<m<<endl;
    return 0;
}