#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    vector<vector<unsigned>> v(n, vector<unsigned>(m));
    unsigned maximum = 0;
    for (size_t i = 0; i != n; ++i)
    {
        for (size_t j = 0; j != m; ++j)
        {
            cin >> v[i][j];
            if (v[i][j] > maximum) maximum = v[i][j];
        }
    }

    vector<vector<pair<size_t, size_t>>> v(maximum + 1);
    v[0].reserve(m);
    for (size_t i = 0; i != m; ++i)
    {
        v[0].emplace_back(pair<size_t, size_t>{0, i});
    }

    return 0;
}
