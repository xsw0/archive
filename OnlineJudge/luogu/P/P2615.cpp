#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    vector<vector<size_t>> v(n, vector<size_t>(n, 0));
    size_t i = 0, j = n / 2;
    v[i][j] = 1;
    size_t x = 2;
    while (x <= n * n) {
        if (i == 0 && j + 1 != n) {
            i = n - 1;
            ++j;
        } else if (j + 1 == n && i != 0) {
            j = 0;
            --i;
        } else if (i == 0 && j + 1 == n) {
            ++i;
        } else {
            if (!v[i - 1][j + 1]) {
                --i;
                ++j;
            } else {
                ++i;
            }
        }
        v[i][j] = x;
        ++x;
    }

    for (auto &w : v) {
        for (auto k : w) {
            cout << k << " ";
        }
        cout << "\n";
    }

    return 0;
}
