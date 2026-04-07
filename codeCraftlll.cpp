#include<iostream>
#include<string>
using namespace std;
void findMonth(){
    string months[12] = {"January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"};
    string cmonth;
    int n;
    cin>>cmonth;
    cin>>n;
    int cindex=0;
    for(int i=0;i<=11;i++){
        if(months[i]==cmonth){
            cindex=i;
            break;
        }
    }
    int tindex=(cindex+n)%12;
    cout<<months[tindex]<<"\n";
}
int main(){
    findMonth();
    return 0;
}