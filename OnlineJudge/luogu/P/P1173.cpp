#include "bits/stdc++.h"

using namespace std;

struct Point {
    size_t x;
    size_t y;
    Point(size_t x, size_t y) : x{x}, y{y} {}
    bool operator==(const Point rhs) const { return x == rhs.x && y == rhs.y; }
};

template <> struct std::hash<Point> {
    std::size_t operator()(const Point &p) const noexcept {
        std::size_t h1 = std::hash<size_t>{}(p.x);
        std::size_t h2 = std::hash<size_t>{}(p.y);
        return h1 ^ (h2 << 1);
    }
};

bool find_points(vector<Point> v, size_t n, size_t m) {
    vector<vector<bool>> has(n, vector<bool>(m));
    for (auto &p : v) { has[p.x][p.y] = true; }
    vector<Point> p;
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            if (!has[i][j]) p.emplace_back(i, j);
        }
    }
    assert(p.size() == 2);
    if (p.front().x != p.back().x && p.front().y != p.back().y) {
        return true;
    } else {
        int x = (int(p.front().x) - int(p.back().x)) +
                (int(p.front().y) - int(p.back().y));
        return abs(x) >= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    while (T--) {
        size_t n, m, c;
        cin >> n >> m >> c;
        vector<Point> points;
        points.reserve(c);
        while (c--) {
            size_t x, y;
            cin >> x >> y;
            --x, --y;
            points.emplace_back(x, y);
        }

        switch (static_cast<uint64_t>(n) * static_cast<uint64_t>(m) -
                points.size()) {
        case 0:
        case 1: cout << "-1\n"; break;
        case 2: cout << (find_points(points, n, m) ? "0\n" : "-1\n"); break;
        default:
            if (min(n, m) == 1) {
                vector<bool> b(max(n, m));
                if (n == 1) {
                    for (auto &p : points) b[p.y] = true;
                } else {
                    for (auto &p : points) b[p.x] = true;
                }
                auto l = find(b.cbegin(), b.cend(), false);
                auto r = find(b.crbegin(), b.crend(), false).base();
                if (r - l == max(n, m) - points.size()) cout << "1\n";
                else cout << "0\n";
            } else {
                unordered_set<Point> us{points.cbegin(), points.cend()};
                bool zero = false;
                bool one = false;
                for (auto &p : points) {
                    auto check = [&](size_t i, size_t j) {
                        return i < n && j < n;
                    };
                    auto has = [&](size_t i, size_t j) {
                        return check(i, j) && us.find({i, j}) == us.end();
                    };
                    auto count = [&](size_t i, size_t j) {
                        if (has(i, j)) {
                            size_t result = 0;
                            if (has(i, j - 1)) ++result;
                            if (has(i, j + 1)) ++result;
                            if (has(i - 1, j)) ++result;
                            if (has(i + 1, j)) ++result;
                            if (result == 0) zero = true;
                            if (result == 1) one = true;
                        }
                    };
                    count(p.x, p.y - 1);
                    count(p.x, p.y + 1);
                    count(p.x - 1, p.y);
                    count(p.x + 1, p.y);
                }
                if (zero) cout << "0\n";
                else if (one || min(n, m) == 1) cout << "1\n";
                else cout << "2\n";
            }
            break;
        }
    }

    return 0;
}
