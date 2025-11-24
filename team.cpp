#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b,c;
    int m=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        int s=a+b+c;
        if(s>=2){
            m++;
        }
    }
    cout<<m<<endl;
    return 0;
}