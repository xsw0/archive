#include "bits/stdc++.h"

using namespace std;

struct PA {
    int p;
    int a;
    PA(){};
    PA(int p, int a) : p{p}, a{a} {};
    bool operator<(const PA &rhs) const {
        return p < rhs.p || p == rhs.p && a > rhs.a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    size_t m;
    cin >> n >> m;
    vector<PA> v(m);
    for (size_t i = 0; i != m; ++i) { cin >> v[i].p >> v[i].a; }

    sort(v.begin(), v.end());

    int tot = 0;
    for (auto x : v) {
        if (x.a < n) {
            n -= x.a;
            tot += x.p * x.a;
        } else {
            tot += x.p * n;
            break;
        }
    }

    cout << tot << endl;

    return 0;
}
