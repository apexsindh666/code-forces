#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int pos = 0; 
    
    for(int step = 1; step <= n-1; step++){
        pos = (pos + step) % n;
        cout << pos + 1;  
        if(step != n-1) cout << " ";
    }
    cout << "\n";
    return 0;
}