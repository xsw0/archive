#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned l, n, m;
    cin >> l >> n >> m;
    vector<unsigned> v;
    v.reserve(n);
    while (n--) {
        unsigned d;
        cin >> d;
        v.push_back(d);
    }

    unsigned left = 0, right = l + 1;
    while (left + 1 < right) {
        unsigned mid = left + (right - left + 1) / 2;
        unsigned count = 0;
        unsigned last = 0;
        for (size_t i = 0; i != v.size(); ++i) {
            if (v[i] - last < mid)
                ++count;
            else
                last = v[i];
        }
        if (count > m)
            right = mid;
        else
            left = mid;
    }
    cout << left << endl;

    return 0;
}
