#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

const vector<unsigned> table = []()
{
    // 9220 02 29
    vector<unsigned> days = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<unsigned> result;

    for (unsigned month = 1; month <= 12; ++month)
    {
        for (unsigned day = 1; day <= days[month]; ++day)
        {
            unsigned rv_month = ((month % 10) * 10) + month / 10;
            unsigned rv_day = ((day % 10) * 10) + day / 10;
            if (rv_day >= 10)
            {
                result.push_back(rv_day * 1000000 + rv_month * 10000 + month * 100 + day);
            }
        }
    }
    sort(result.begin(), result.end());
    return result;
}();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned data1, data2;
    cin >> data1 >> data2;
    auto first = lower_bound(table.begin(), table.end(), data1);
    auto last = upper_bound(table.begin(), table.end(), data2);

    cout << last - first << endl;
    return 0;
}
