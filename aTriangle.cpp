#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll area2(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3) {
    return abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
}

bool isRight(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3) {
    if (area2(x1,y1,x2,y2,x3,y3) == 0) return false; 

    ll d1 = (x2-x1)*(x3-x1) + (y2-y1)*(y3-y1); 
    ll d2 = (x1-x2)*(x3-x2) + (y1-y2)*(y3-y2); 
    ll d3 = (x1-x3)*(x2-x3) + (y1-y3)*(y2-y3); 

    return d1==0 || d2==0 || d3==0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x[3], y[3];
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    if (isRight(x[0],y[0],x[1],y[1],x[2],y[2])) {
        cout << "RIGHT\n";
        return 0;
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 3; i++) {          
        for (int d = 0; d < 4; d++) {      
            ll tx[3] = {x[0], x[1], x[2]};
            ll ty[3] = {y[0], y[1], y[2]};
            tx[i] = x[i] + dx[d];
            ty[i] = y[i] + dy[d];

            if (isRight(tx[0],ty[0],tx[1],ty[1],tx[2],ty[2])) {
                cout << "ALMOST\n";
                return 0;
            }
        }
    }
    cout << "NEITHER\n";
    return 0;
}