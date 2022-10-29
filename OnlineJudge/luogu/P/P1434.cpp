#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    size_t R, C;
    cin >> R >> C;
    vector<vector<int>> v;
    v.resize(R);
    vector<vector<int>> mm(R, vector<int>(C, 0));
    for (auto &row : v)
    {
        row.reserve(C);
        for (size_t i = 0; i < C; ++i)
        {
            int n;
            cin >> n;
            row.push_back(n);
        }
    }

    int result = 0;

    for (size_t i = 0; i < R; ++i)
    {
        for (size_t j = 0; j < C; ++j)
        {
            function<void(int, size_t, size_t)> f =
                [&](int h, size_t x, size_t y) {
                    if (h > mm[x][y])
                    {
                        mm[x][y] = h;
                        if (x + 1 < R && v[x + 1][y] > v[x][y])
                            f(h + 1, x + 1, y);
                        if (y + 1 < C && v[x][y + 1] > v[x][y])
                            f(h + 1, x, y + 1);
                        if (x != 0 && v[x - 1][y] > v[x][y])
                            f(h + 1, x - 1, y);
                        if (y != 0 && v[x][y - 1] > v[x][y])
                            f(h + 1, x, y - 1);
                    }
                    result = max(result, mm[x][y]);
                };
            f(1, i, j);
        }
    }
    cout << result << endl;

    return 0;
}
