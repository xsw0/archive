#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    while (m--)
    {
        size_t x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1;
        ++v[x1][y1];
        if (x2 != n) --v[x2][y1];
        if (y2 != n) --v[x1][y2];
        if (x2 != n && y2 != n) ++v[x2][y2];
    }

    vector<int> cols(n);
    for (size_t i = 0; i != n; ++i)
    {
        int row = 0;
        for (size_t j = 0; j != n; ++j)
        {
            auto sum = row + cols[j] + v[i][j];
            cout << sum << " ";
            row += v[i][j];
            cols[j] = sum;
        }
        cout << "\n";
    }

    return 0;
}
