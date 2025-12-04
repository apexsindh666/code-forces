#include<iostream>
using namespace std;
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    int p=(n+a-1)/a;
    int q=(m+a-1)/a;
    int r=p*q;
    cout<<r<<endl;
    return 0;
}
// #include<iostream>
// using namespace std;
// int main(){
//     long long n, m, a;
//     cin >> n >> m >> a;
//     long long p = (n + a - 1) / a;
//     long long q = (m + a - 1) / a;
//     long long r = p * q;
//     cout << r << endl;
//     return 0;
// }
