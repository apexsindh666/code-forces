#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    map<string,int> cnt;
    for(int i=0;i<n;i++){string s;cin>>s;cnt[s]++;}
    string winner; int best=0;
    for(auto&p:cnt)if(p.second>best){best=p.second;winner=p.first;}
    cout<<winner;
}