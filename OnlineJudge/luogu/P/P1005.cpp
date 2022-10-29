#include "bits/stdc++.h"

using namespace std;

string u2s(unsigned __int128 n) {
    string result;
    while (n > 0) {
        result.push_back('0' + n % 10);
        n /= 10;
    }
    return result.empty() ? "0" : string{result.crbegin(), result.crend()};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    unsigned __int128 sum = 0;
    while (n--) {
        vector<size_t> v;
        v.reserve(m);
        for (size_t i = 0; i < m; ++i) {
            size_t a;
            cin >> a;
            v.emplace_back(a);
        }

        map<pair<size_t, size_t>, unsigned __int128> table{};
        function<unsigned __int128(size_t, size_t)> count =
            [&](size_t first, size_t last) -> unsigned __int128 {
            if (first == last)
                return 0;
            auto it = table.find({first, last});
            if (table.find({first, last}) == table.end()) {
                it = table.insert({{first, last}, 0}).first;
                it->second = max(v[first] + 2 * count(first + 1, last),
                                 2 * count(first, last - 1) + v[last - 1]);
            }
            return it->second;
        };

        unsigned __int128 line = count(size_t(0), m);
        sum += line;
    }

    cout << u2s(sum * 2) << endl;

    return 0;
}
