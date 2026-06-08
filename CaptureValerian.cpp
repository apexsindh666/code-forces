#include <bits/stdc++.h>
using namespace std;

// Big integer as vector of digits (base 10^9 for efficiency)
// But since we need base conversion, we'll use base-10^9 internally
// and do division/mod for conversion.
// Actually: store as vector<int> representing decimal digits for simplicity,
// since max is 10^1515 and we only need divide/mod by small numbers (2-25).

struct BigInt {
    // Stored as base-10^9 limbs, little-endian
    static const int BASE = 1000000000;
    vector<int> d; // d[0] = least significant

    BigInt() {}
    BigInt(int v) { if (v) d.push_back(v); }

    bool isZero() const { return d.empty(); }

    // Multiply by small int, add small int (for base conversion from string)
    BigInt mulAdd(int mul, int add) const {
        BigInt res;
        long long carry = add;
        for (int x : d) {
            carry += (long long)x * mul;
            res.d.push_back(carry % BASE);
            carry /= BASE;
        }
        while (carry) {
            res.d.push_back(carry % BASE);
            carry /= BASE;
        }
        // trim leading zeros
        while (!res.d.empty() && res.d.back() == 0) res.d.pop_back();
        return res;
    }

    // Divide by small int, return remainder
    pair<BigInt, int> divmod(int m) const {
        BigInt q;
        q.d.resize(d.size());
        long long rem = 0;
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            long long cur = rem * BASE + d[i];
            q.d[i] = cur / m;
            rem = cur % m;
        }
        while (!q.d.empty() && q.d.back() == 0) q.d.pop_back();
        return {q, (int)rem};
    }
};

int charToDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char digitToChar(int d) {
    if (d < 10) return '0' + d;
    return 'A' + d - 10;
}

string toRoman(int n) {
    // Standard Roman numeral conversion
    const int vals[]   = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const char* syms[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string res;
    for (int i = 0; i < 13; i++) {
        while (n >= vals[i]) {
            res += syms[i];
            n -= vals[i];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    string bStr, c;
    cin >> a >> bStr >> c;

    // Parse c (base a) into BigInt
    BigInt num(0);
    for (char ch : c) {
        num = num.mulAdd(a, charToDigit(ch));
    }

    bool roman = (bStr == "R");

    if (roman) {
        // Number fits in int (guaranteed <= 3000)
        // Extract int from BigInt
        auto [q1, r1] = num.divmod(1000000000);
        int val = 0;
        if (!q1.isZero()) {
            // q1 has higher part — combine
            // Since <= 3000, fits in one limb or two small ones
            long long v = 0;
            long long base = 1;
            for (int x : num.d) {
                v += x * base;
                base *= 1000000000LL;
            }
            val = (int)v;
        } else {
            val = r1;
        }
        cout << toRoman(val) << "\n";
    } else {
        int b = stoi(bStr);
        if (num.isZero()) {
            cout << "0\n";
            return 0;
        }

        string result;
        while (!num.isZero()) {
            auto [q, r] = num.divmod(b);
            result += digitToChar(r);
            num = q;
        }
        reverse(result.begin(), result.end());
        cout << result << "\n";
    }

    return 0;
}