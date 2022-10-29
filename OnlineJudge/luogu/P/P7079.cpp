#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    array<bool, 26> arr{};
    while (n--) {
        string s;
        cin >> s;
        if (s.front() >= 'A' && s.front() <= 'Z') {
            arr[s.front() - 'A'] = true;
        }
    }

    for (size_t i = 0; i != arr.size(); ++i) {
        if (!arr[i]) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 26 << endl;

    return 0;
}
