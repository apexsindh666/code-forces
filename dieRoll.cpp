// // Step 1: Input the two rolls
// Input Y, W
// // Step 2: Find the maximum roll Dot has to beat or tie
// MaxRoll = Maximum(Y, W)

// // Step 3: Calculate the number of winning faces (from MaxRoll to 6)
// Numerator = 6 - MaxRoll + 1
// Denominator = 6

// // Step 4: Simplify the fraction using GCD
// CommonDivisor = GCD(Numerator, Denominator)

// FinalNumerator = Numerator / CommonDivisor
// FinalDenominator = Denominator / CommonDivisor

// // Step 5: Output in A/B format
// Print FinalNumerator + "/" + FinalDenominator
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int Y, W;
    cin >> Y >> W;
    int MaxRoll = max(Y, W);
    int Numerator = 6 - MaxRoll + 1;
    int Denominator = 6;
    int CommonDivisor = gcd(Numerator, Denominator);
    int FinalNumerator = Numerator / CommonDivisor;
    int FinalDenominator = Denominator / CommonDivisor;
    cout << FinalNumerator << "/" << FinalDenominator << endl;
    return 0;
}