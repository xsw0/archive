#include "bits/stdc++.h"

using namespace std;

string f(unsigned n) {
    switch (n) {
    case 0: return "0";
    case 1: return "2(0)";
    case 2: return "2";
    default: {
        string result;
        size_t i = 0;
        while (n != 0) {
            if (n % 2 != 0) {
                string s = (i == 1) ? "+2" : "+2(" + f(i) + ")";
                result += string{s.crbegin(), s.crend()};
            }
            n /= 2;
            ++i;
        }
        result.pop_back();
        return string{result.crbegin(), result.crend()};
    }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
