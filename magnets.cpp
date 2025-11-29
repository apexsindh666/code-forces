#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    string prev, cur;
    cin >> prev; 

    int count = 1;

    for(int i = 1; i < n; i++){
        cin >> cur;
        if(cur != prev){
            count++;
        }
        prev = cur;
    }

    cout << count << endl;
    return 0;
}
