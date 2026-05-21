#include<bits/stdc++.h>
using namespace std;

bool valid(int x, int y) {
    return x <= 2 * y + 2 && y <= 2 * x + 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(valid(a, b) && valid(c - a, d - b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}