#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    array<int, 7> first{};
    array<int, 7> last{};
    for (size_t i = 0; i != first.size(); ++i)
    {
        first[i] = -1;
        last[i] = -1;
    }
    first[0] = 0;

    int sum = 0;
    for (int i = 0; i != n; ++i)
    {
        int id;
        cin >> id;
        sum += id;
        sum %= 7;
        if (first[sum] == -1)
        {
            first[sum] = i + 1;
        }
        else
        {
            last[sum] = i + 1;
        }
    }

    int maximum = 0;
    for (size_t i = 0; i < first.size(); ++i)
    {
        if (first[i] != -1 && last[i] != -1)
        {
            maximum = max(maximum, last[i] - first[i]);
        }
    }
    cout << maximum << endl;

    return 0;
}
