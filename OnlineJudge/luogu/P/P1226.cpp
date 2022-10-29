#include "bits/stdc++.h"

using namespace std;

uint64_t a, b, p;

uint64_t fp(uint64_t x, uint64_t y) {
    if (y == 0) {
        return 1;
    } else if (y % 2 == 0) {
        return fp(x * x % p, y / 2) % p;
    } else {
        return x * fp(x, y - 1) % p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> p;
    uint64_t result;
    if (a < 2) result = a;
    else result = fp(a % p, b);
    cout << a << "^" << b << " mod " << p << "=" << result << endl;

    return 0;
}
