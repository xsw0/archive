#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint64_t n;
    cin >> n;
    vector<uint64_t> v;
    v.reserve(n);
    while (n--) {
        uint64_t h;
        cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());

    uint64_t tot = 0;

    uint64_t h = 0;

    uint64_t l = 0;
    uint64_t r = v.size();
    while (true) {
        if (l >= r)
            break;
        --r;
        tot += (v[r] - h) * (v[r] - h);
        h = v[r];
        if (l >= r)
            break;
        tot += (h - v[l]) * (h - v[l]);
        h = v[l];
        ++l;
    }

    cout << tot << endl;

    return 0;
}
