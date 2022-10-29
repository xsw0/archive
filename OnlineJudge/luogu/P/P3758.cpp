#include "bits/stdc++.h"

using namespace std;

struct Point {
    vector<size_t> adjacent;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    static constexpr size_t mod = 2017;

    size_t n, m;
    cin >> n >> m;
    vector<Point> points(n);
    while (m--) {
        size_t u, v;
        cin >> u >> v;
        --u, --v;
        points[u].adjacent.push_back(v);
        points[v].adjacent.push_back(u);
    }
    size_t t;
    cin >> t;

    vector<size_t> count(n);
    count.front() = 1;

    size_t sum = 0;
    for (size_t i = 0; i != t; ++i) {
        auto x = count;
        for (size_t index = 0; index != n; ++index) {
            sum += count[index];
            sum %= mod;
            for (auto adj : points[index].adjacent) {
                x[adj] += count[index];
                x[adj] %= mod;
            }
        }
        count = x;
    }

    for (auto n : count) {
        sum += n;
        sum %= mod;
    }
    cout << sum << endl;

    return 0;
}
