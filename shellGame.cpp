#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Standard CP practice for file-based problems
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int ball;
    if (!(fin >> ball)) return 0;

    for (int i = 0; i < 3; i++) {
        int a, b;
        fin >> a >> b;
        
        // If the ball is in one of the cups being swapped, 
        // move it to the other cup's position.
        if (a == ball) {
            ball = b;
        } else if (b == ball) {
            ball = a;
        }
    }

    fout << ball << endl;

    return 0;
}