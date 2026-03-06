#include<iostream>
#include<string>
using namespace std;
void shiftSort(){
    int n,k=0,misplaced=0;
    cin>>n;
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]=='0')k++;
    }    
    for(int i=0;i<k;i++){
        if(s[i]=='1')misplaced+=1;
    }
    cout<<misplaced<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        shiftSort();
    }
    return 0;
}