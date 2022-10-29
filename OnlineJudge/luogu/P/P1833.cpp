#include "bits/stdc++.h"

using namespace std;

struct CherryTree {
    size_t time;
    size_t value;
    size_t count;
};

class dpHasher {
  public:
    size_t operator()(const array<size_t, 3> &arr) const {
        return std::hash<size_t>()(arr[0] ^ arr[1] ^ arr[2]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    size_t time;
    {
        size_t startHH, startMM, endHH, endMM;
        char c;
        cin >> startHH >> c >> startMM >> endHH >> c >> endMM >> n;
        time = (endHH - startHH) * 60 + endMM - startMM;
    }
    vector<CherryTree> CherryTrees;
    CherryTrees.reserve(n);
    map<size_t, size_t> limit;
    for (size_t i = 0; i < n; ++i) {
        size_t t, v, c;
        cin >> t >> v >> c;
        if (t <= time) {
            if (c == 0) {
                auto it = limit.lower_bound(v);
                if (it == limit.end() || it->second > t) {
                    if (it->first == v) {
                        it->second = t;
                    } else {
                        limit.insert({v, t});
                        --it;
                    }

                    while (it != limit.begin() && prev(it)->second >= t) {
                        it = limit.erase(prev(it));
                    }
                    // CherryTrees.emplace_back(CherryTree{t, v, time / t});
                }
            } else {
                CherryTrees.emplace_back(CherryTree{t, v, min(c, time / t)});
            }
        }
    }

    {
        vector<CherryTree> new_CherryTrees;
        new_CherryTrees.reserve(CherryTrees.size());
        for (auto &tree : CherryTrees) {
            auto it = limit.lower_bound(tree.value);
            if (it == limit.end() || it->second > tree.time) {
                new_CherryTrees.push_back(tree);
            }
        }
        CherryTrees = new_CherryTrees;
        for (auto &p : limit) {
            CherryTrees.emplace_back(
                CherryTree{p.second, p.first, time / p.second});
        }
    }

    unordered_map<array<size_t, 3>, size_t, dpHasher> dp;

    function<size_t(size_t, size_t, size_t)> f = [&](size_t t, size_t i,
                                                     size_t j) -> size_t {
        if (dp.find({t, i, j}) == dp.end()) {
            if (t == 0) {
                return 0;
            } else if (i == 0 && j == 0) {
                dp[{t, i, j}] =
                    CherryTrees[0].time > t ? 0 : CherryTrees[0].value;
            } else if (t < CherryTrees[i].time) {
                if (i == 0) {
                    dp[{t, i, j}] = 0;
                } else {
                    dp[{t, i, j}] = f(t, i - 1, CherryTrees[i - 1].count - 1);
                }
            } else {
                size_t prevI = j == 0 ? i - 1 : i;
                size_t prevJ = j == 0 ? CherryTrees[i - 1].count - 1 : j - 1;
                auto current = CherryTrees[i].value;
                auto preTot = f(t - CherryTrees[i].time, prevI, prevJ);
                auto exceptCurrent = f(t, prevI, prevJ);
                dp[{t, i, j}] = max(preTot + current, exceptCurrent);
            }
        }
        return dp[{t, i, j}];
    };

    std::cout << f(time, CherryTrees.size() - 1, CherryTrees.back().count - 1)
              << endl;

    return 0;
}