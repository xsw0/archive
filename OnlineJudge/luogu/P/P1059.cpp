#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    set<int> s;
    while (n--) {
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << s.size() << "\n";
    for (auto a : s) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
