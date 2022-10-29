#include "bits/stdc++.h"

using namespace std;

template <typename It>
void quicksort(It first, It last)
{
    if (first == last) return;
    auto pivot = prev(last);
    auto l = first;
    auto r = pivot;
    while (l != r)
    {
        if (*l > *pivot)
        {
            --r;
            swap(*l, *r);
        }
        else
        {
            ++l;
        }
    }
    swap(*pivot, *r);
    quicksort(first, r);
    quicksort(next(r), last);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    while (n--)
    {
        int a;
        cin >> a;
        v.emplace_back(a);
    }
    quicksort(v.begin(), v.end());
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
