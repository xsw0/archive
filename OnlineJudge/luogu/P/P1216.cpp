#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    for (size_t i = 0; i < n; i++)
    {
        int pre = 0;
        for (size_t j = 0; j < i; ++j)
        {
            int x;
            cin >> x;
            swap(v[j], pre);
            v[j] = max(pre, v[j]) + x;
        }
        int x;
        cin >> x;
        v.push_back(pre + x);
    }

    cout << *max_element(v.cbegin(), v.cend()) << endl;

    return 0;
}
