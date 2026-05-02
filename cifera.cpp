#include<bits/stdc++.h>
using namespace std;

int main(){
    long long k, l;
    cin >> k >> l;
    
    long long cur = k;
    int power = 1;
    
    while(cur < l){
        cur *= k;
        power++;
        if(cur > l || cur < 0) break; 
    }
    
    if(cur == l){
        cout << "YES" << endl;
        cout << power - 1 << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}