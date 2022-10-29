#include "bits/stdc++.h"

using namespace std;

unordered_map<size_t, size_t> um{};

size_t count2(size_t n) {
    if (n < 10) {
        return n >= 2;
    }
    auto it = um.find(n);
    if (it == um.end()) {
        it = um.insert({n, 0}).first;

        size_t x = 100000;
        while (n < x)
            x /= 10;
        auto first = n / x;

        if (first > 2) {
            it->second += x;
        } else if (first == 2) {
            it->second += n % x + 1;
        }
        it->second += (n / x) * count2(x - 1) + count2(n % x);
    }
    return it->second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t l, r;
    cin >> l >> r;

    cout << count2(r) - count2(l - 1) << endl;

    return 0;
}
