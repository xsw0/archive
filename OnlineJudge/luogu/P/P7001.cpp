#include "bits/stdc++.h"

using namespace std;

bool check(const string &s1, const string s2) {
    assert(s1.size() == 9);
    assert(s2.size() == 9);
    for (size_t i = 0; i != 9; ++i) {
        if (s1[i] != '*' && s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    s.reserve(9);
    cin >> s;
    int n;
    cin >> n;
    vector<string> v;
    v.reserve(n);
    while (n--) {
        string s2;
        s2.reserve(9);
        cin >> s2;
        if (check(s, s2)) {
            v.push_back(s2);
        }
    }
    cout << v.size() << "\n";
    for (auto &s : v) {
        cout << s << "\n";
    }

    return 0;
}
