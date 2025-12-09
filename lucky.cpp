#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int lsum=0,rsum=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        lsum=s[0]+s[1]+s[2];
        rsum=s[3]+s[4]+s[5];
        if(lsum==rsum){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}