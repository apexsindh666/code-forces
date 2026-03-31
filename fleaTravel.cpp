#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n > 0 && (n & (n - 1)) == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}