#include <functional>
#include <iomanip>
#include <iostream>
#include <vector>

#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t BX, BY, horseX, horseY;
    cin >> BX >> BY >> horseX >> horseY;
    vector<vector<long long>> v(BX + 1, vector<long long>(BY + 1));
    auto f = [&](size_t x, size_t y) {
        if (x < v.size() && y < v[x].size()) { v[x][y] = -1; }
    };
    v[0][0] = 1;
    f(horseX + 2, horseY + 1);
    f(horseX + 1, horseY + 2);
    f(horseX - 2, horseY + 1);
    f(horseX - 1, horseY + 2);
    f(horseX - 2, horseY - 1);
    f(horseX - 1, horseY - 2);
    f(horseX + 2, horseY - 1);
    f(horseX + 1, horseY - 2);
    f(horseX, horseY);
    std::function<long long(size_t x, size_t y)> f2 =
        [&](size_t x, size_t y) -> long long {
        switch (v[x][y]) {
        case -1: return 0;
        case 0: {
            long long U = (x == 0 ? 0 : f2(x - 1, y));
            long long L = (y == 0 ? 0 : f2(x, y - 1));
            v[x][y] = U + L;
        }
        default: return v[x][y];
        }
    };
    cout << f2(BX, BY);
    return 0;
}
