#include<iostream>
using namespace std;
void yes(string s){
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='Y') c++;
    }
    if(c<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
int t;
string s;
cin>>t;
for(int i=0;i<t;i++){
cin>>s;
yes(s);
}
    return 0;
}