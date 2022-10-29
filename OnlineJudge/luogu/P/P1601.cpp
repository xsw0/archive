#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c;

    size_t size = max(a.size(), b.size());
    c.reserve(1 + size);

    int carry = 0;
    size_t i = 0;

    while (i != size) {
        int n1 = i < a.size() ? a[i] - '0' : 0;
        int n2 = i < b.size() ? b[i] - '0' : 0;
        auto sum = carry + n1 + n2;
        c.push_back('0' + sum % 10);
        carry = sum / 10;
        ++i;
    }
    if (carry) c.push_back('0' + carry);

    reverse(c.begin(), c.end());

    cout << c << endl;

    return 0;
}
