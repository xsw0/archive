#include "bits/stdc++.h"

using namespace std;

void add(string &s, size_t index, unsigned n) {
    if (n == 0) return;
    if (s.size() <= index) s.resize(index + 1, '0');
    unsigned sum = (s[index] - '0') + n;
    s[index] = '0' + sum % 10;
    add(s, index + 1, sum / 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c;
    c.reserve(a.size() + b.size());

    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b.size(); ++j) {
            add(c, i + j, (a[i] - '0') * (b[j] - '0'));
        }
    }

    reverse(c.begin(), c.end());
    cout << (c.empty() ? "0" : c) << endl;
    return 0;
}
