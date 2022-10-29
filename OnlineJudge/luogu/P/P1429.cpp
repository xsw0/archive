#include "bits/stdc++.h"

using namespace std;

struct Point
{
    int64_t x;
    int64_t y;
    Point(int64_t x, int64_t y) : x{x}, y{y} {}
    int64_t operator-(const Point &rhs) const
    {
        return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y);
    }
    static bool cmp_x(const Point &lhs, const Point &rhs)
    {
        return lhs.x < rhs.x;
    }
    static bool cmp_y(const Point &lhs, const Point &rhs)
    {
        return lhs.y < rhs.y;
    }
};

int64_t distance2(vector<Point>::iterator first, vector<Point>::iterator last)
{
    size_t size = distance(first, last);
    if (size < 4)
    {
        int64_t minimum = numeric_limits<int64_t>::max();

        for (auto it = first; it != last; ++it)
        {
            for (auto it2 = next(it); it2 != last; ++it2)
            {
                if (*it2 - *it < minimum) minimum = *it2 - *it;
            }
        }
        sort(first, last, Point::cmp_y);
        return minimum;
    }
    else
    {
        auto mid = first + size / 2;
        int64_t minimum = min(distance2(first, mid), distance2(mid, last));
        vector<Point> result;
        result.reserve(size);
        merge(first, mid, mid, last, back_inserter(result), Point::cmp_y);
        copy(result.begin(), result.end(), first);
        int64_t sq = ceil(sqrt(minimum));
        assert(sq * sq >= minimum);
        result.clear();
        copy_if(first,
                last,
                back_inserter(result),
                [&](const Point &p) { return p.x - mid->x <= sq; });
        for (auto it = result.cbegin(); it != result.cend(); ++it)
        {
            for (auto it2 = next(it);
                 it2 != result.cend() && it2->y < it->y + sq;
                 ++it2)
            {
                if (*it2 - *it < minimum)
                {
                    minimum = *it2 - *it;
                }
            }
        }
        return minimum;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;

    vector<Point> v;
    while (n--)
    {
        int64_t x, y;
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end(), Point::cmp_x);
    cout << fixed << setprecision(4) << sqrt(distance2(v.begin(), v.end()))
         << endl;

    return 0;
}
