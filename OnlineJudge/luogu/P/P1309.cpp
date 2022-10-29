#include "bits/stdc++.h"

using namespace std;

struct Person {
    unsigned score;
    unsigned weight;
    bool operator<(const Person &rhs) const { return score > rhs.score; };
    bool operator==(const Person &rhs) const { return score == rhs.score; };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, r, q;
    cin >> n >> r >> q;
    vector<Person> v(n * 2);
    vector<size_t> order(n * 2);
    for (size_t i = 0; i != n * 2; ++i)
        order[i] = i;
    for (size_t i = 0; i != n * 2; ++i)
        cin >> v[i].score;
    for (size_t i = 0; i != n * 2; ++i)
        cin >> v[i].weight;
    auto cmp = [&](size_t lhs, size_t rhs) {
        return v[lhs] < v[rhs] || v[lhs] == v[rhs] && lhs < rhs;
    };
    sort(order.begin(), order.end(), cmp);
    for (size_t i = 0; i != r; ++i) {
        vector<size_t> win, lose;
        win.reserve(n), lose.reserve(n);
        for (size_t j = 0; j < n; ++j) {
            if (v[order[j * 2]].weight > v[order[j * 2 + 1]].weight) {
                ++v[order[j * 2]].score;
                win.push_back(order[j * 2]);
                lose.push_back(order[j * 2 + 1]);
            } else {
                ++v[order[j * 2 + 1]].score;
                win.push_back(order[j * 2 + 1]);
                lose.push_back(order[j * 2]);
            }
        }
        order.clear();
        std::merge(win.begin(), win.end(), lose.begin(), lose.end(),
                   std::back_inserter(order), cmp);
    }
    cout << order[q - 1] + 1 << endl;

    return 0;
}
