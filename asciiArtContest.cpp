#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int g,c,l;
    cin>>g>>c>>l;
    int ma=max(g,max(c,l));
    int mi=min(g,min(c,l));
    if(ma-mi>=10){
        cout<<"check again\n";
    }else{
        int s=(g+c+l);
        int r=s-ma-mi;
        cout<<"final "<<r<<"\n";
    }
    return 0;
}