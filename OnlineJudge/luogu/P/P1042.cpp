#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char c;

    int win11 = 0;
    int win21 = 0;

    int lost11 = 0;
    int lost21 = 0;

    vector<pair<int, int>> record21{};

    while (cin >> c && c != 'E') {
        bool win = c == 'W';
        if (win) {
            ++win11;
            ++win21;
        } else {
            ++lost11;
            ++lost21;
        }
        if (abs(win11 - lost11) >= 2 && (win11 >= 11 || lost11 >= 11)) {
            cout << win11 << ":" << lost11 << "\n";
            win11 = 0;
            lost11 = 0;
        }
        if (abs(win21 - lost21) >= 2 && (win21 >= 21 || lost21 >= 21)) {
            record21.emplace_back(win21, lost21);
            win21 = 0;
            lost21 = 0;
        }
    }
    cout << win11 << ":" << lost11 << "\n";
    record21.emplace_back(win21, lost21);
    cout << "\n";
    for (auto &p : record21) {
        cout << p.first << ":" << p.second << "\n";
    }

    return 0;
}
