#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    size_t size;
    cin >> size;
    vector<int> v;
    v.reserve(size);
    for (size_t i = 0; i < size; ++i)
    {
        int x;
        cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (size_t i = 2; i < v.size(); i++)
    {
        size_t l = 0;
        size_t r = i - 1;
        while (l < r)
        {
            if (v[l] + v[r] == v[i])
            {
                ++count;
                break;
            }
            else if (v[l] + v[r] < v[i])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
    }
    cout << count << endl;
    return 0;
}
