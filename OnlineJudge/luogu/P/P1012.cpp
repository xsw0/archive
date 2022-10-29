#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    vector<string> v;
    while (n--) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.rbegin(), v.rend(), [](const string &lhs, const string &rhs) {
        size_t min_size = min(lhs.size(), rhs.size());
        for (size_t i = 0; i < min_size; ++i) {
            if (lhs[i] < rhs[i])
                return true;
            if (lhs[i] > rhs[i])
                return false;
        }
        size_t max_size = max(lhs.size(), rhs.size());

        for (size_t i = min_size; i < max_size; ++i) {
            if (lhs[i % lhs.size()] < rhs[i % rhs.size()])
                return true;
            if (lhs[i % lhs.size()] > rhs[i % rhs.size()])
                return false;
        }
        return false;
    });
    for (auto &s : v) {
        cout << s;
    }
    cout << endl;

    return 0;
}
