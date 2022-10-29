#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<array<unsigned, 4>> v;
    v.reserve(n);
    for (size_t i = 0; i < n; ++i)
    {
        unsigned x0, y0, dx, dy;
        cin >> x0 >> y0 >> dx >> dy;
        v.emplace_back(array<unsigned, 4>{x0, y0, dx, dy});
    }
    unsigned x0, y0;
    cin >> x0 >> y0;
    for (auto it = v.crbegin(); it != v.crend(); ++it)
    {
        if (x0 >= (*it)[0] && y0 >= (*it)[1] && x0 <= (*it)[0] + (*it)[2] && y0 <= (*it)[1] + (*it)[3])
        {
            cout << n << endl;
            return 0;
        }
        --n;
    }
    cout << -1 << endl;
    return 0;
}
