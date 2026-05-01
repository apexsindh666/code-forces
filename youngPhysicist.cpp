// READ n
// SET sumX = 0, sumY = 0, sumZ = 0

// FOR i FROM 1 TO n:
//     READ x, y, z
//     sumX = sumX + x
//     sumY = sumY + y
//     sumZ = sumZ + z

// IF sumX == 0 AND sumY == 0 AND sumZ == 0:
//     PRINT "YES"
// ELSE:
//     PRINT "NO"
#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int x,y,z;
    cin>>n;
    int sumx=0,sumy=0,sumz=0;
    for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        sumx+=x;
        sumy+=y;
        sumz+=z;
    }
    if(sumx==0 && sumy ==0 && sumz==0){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,x=0,y=0,z=0,a,b,c;
//     cin>>n;
//     while(n--){cin>>a>>b>>c;x+=a;y+=b;z+=c;}
//     cout<<(x==0&&y==0&&z==0?"YES":"NO");
// }