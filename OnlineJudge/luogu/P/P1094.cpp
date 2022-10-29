#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w, n;
    cin >> w >> n;

    array<int, 201> v{};

    while (n--) {
        int p;
        cin >> p;
        ++v[p];
    }

    int tot = 0;

    int l = 5;
    int r = 200;

    while (l <= r) {
        if (l == r) {
            if (l + r > w) {
                tot += v[l];
            } else {
                tot += (v[l] + 1) / 2;
            }
            break;
        }
        if (l + r > w) {
            tot += v[r];
            --r;
        } else {
            if (v[l] > v[r]) {
                v[l] -= v[r];
                tot += v[r];
                --r;
            } else if (v[l] < v[r]) {
                v[r] -= v[l];
                tot += v[l];
                ++l;
            } else {
                tot += v[l];
                ++l, --r;
            }
        }
    }

    cout << tot << endl;

    return 0;
}
