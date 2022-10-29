#include "bits/stdc++.h"

using namespace std;

string sub(const string &maximum, const string &minimum) {
    int borrow = 0;
    string c;
    c.reserve(maximum.size());
    for (size_t i = 0; borrow || i != minimum.size(); i++) {
        sum = 10 + (maximum - '0') + (minimum - '0');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b, c;
    cin >> a >> b;
    bool neg = false;

    if (a.size() < b.size()) {
        neg = true;
    } else if (a.size() == b.size()) {
        size_t i = 0;
        while (i != a.size() && a[i] == b[i])
            ++i;
        a = a.substr(i, a.size() - i);
        b = b.substr(i, b.size() - i);
        if (!a.empty() && a.front() < b.front())
            neg = true;
    }

    auto &minimum = neg ? a : b;
    auto &maximum = neg ? b : a;

    if (maximum.empty()) {
        cout << "0" << endl;
    } else {
        if (neg)
            cout << "-";
        reverse(maximum.begin(), maximum.end());
        reverse(minimum.begin(), minimum.end());
        cout << sub(maximum, minimum) << endl;
    }

    return 0;
}
