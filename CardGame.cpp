#include<bits/stdc++.h>
using namespace std;

int main(){
    char trump;
    string c1, c2;
    cin >> trump >> c1 >> c2;
    
    string ranks = "6789TJQKA";
    char r1 = c1[0], s1 = c1[1];
    char r2 = c2[0], s2 = c2[1];
    
    int rank1 = ranks.find(r1);
    int rank2 = ranks.find(r2);
    
    if(s1 == s2 && rank1 > rank2)
        cout << "YES";
    else if(s1 == trump && s2 != trump)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}