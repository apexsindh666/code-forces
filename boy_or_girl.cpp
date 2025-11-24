#include<iostream>
#include<set>
using namespace std;
int main(){
    string s;
    cin>>s;
    set<char>p;
    for(int i=0;i<s.size();i++){
        p.insert(s[i]);
    }
    if(p.size()%2==0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}