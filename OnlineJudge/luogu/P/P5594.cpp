#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    size_t n, m, k;
    cin >> n >> m >> k;
    vector<unordered_set<size_t>> v(k + 1);
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            size_t day;
            cin >> day;
            v[day].insert(j);
        }
    }

    for (auto it = next(v.cbegin()); it != v.cend(); ++it)
    {
        cout << it->size() << ' ';
    }
    cout << endl;

    return 0;
}
