#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    while (n--) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    return 0;
}
