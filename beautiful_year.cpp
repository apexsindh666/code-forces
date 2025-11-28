#include <iostream>
#include <set>
using namespace std;

bool distinct(int y) {
set<char> s;
string x = to_string(y);
for (char c : x) s.insert(c);
return s.size() == x.size();
}

int main() {
int y;
cin >> y;
while (true) {
y++;
if (distinct(y)) {
cout << y << endl;
break;
}
}
return 0;
}
