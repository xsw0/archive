#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    size_t N;
    cin >> N;
    vector<size_t> v;
    v.reserve(N);
    for (size_t i = 0; i < N; ++i)
    {
        size_t x;
        cin >> x;
        v.push_back(x);
    }
    vector<size_t> s(v);
    vector<vector<size_t>> way;
    way.reserve(N);
    for (size_t i = 0; i < N; i++)
    {
        way.push_back({i});
    }

    for (size_t i = 0; i < N - 1; ++i)
    {
        for (size_t j = i + 1; j < N; ++j)
        {
            bool b;
            cin >> b;
            if (b)
            {
                if (s[i] + v[j] > s[j])
                {
                    s[j] = s[i] + v[j];
                    way[j] = way[i];
                    way[j].push_back(j);
                }
            }
        }
    }
    size_t index = max_element(s.cbegin(), s.cend()) - s.cbegin();
    for (auto i : way[index])
    {
        cout << i + 1 << ' ';
    }
    cout << endl;
    cout << s[index] << endl;

    return 0;
}
