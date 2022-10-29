#include "bits/stdc++.h"

using namespace std;

array<array<array<uint64_t, 198>, 7>, 198> table{};

uint64_t f(uint64_t n, uint64_t k, uint64_t m) {
    if (m * k < n) return 0;
    if (n == 0 || m * k == n) return 1;
    if (!table[n][k][m]) {
        uint64_t result = f(n, k, m - 1);
        if (n >= m) result += f(n - m, k - 1, m);
        table[n][k][m] = result;
    }
    return table[n][k][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint64_t n, k;
    cin >> n >> k;
    n -= k;
    cout << f(n, k, n) << endl;

    return 0;
}
