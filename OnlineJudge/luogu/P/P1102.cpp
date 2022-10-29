#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

int main()
{
    size_t N;
    int64_t C;
    cin >> N >> C;
    unordered_map<int64_t, size_t> v;
    v.reserve(N);
    for (size_t i = 0; i < N; i++)
    {
        int64_t t;
        cin >> t;
        ++v[t];
    }
    size_t count = 0;
    for (auto &p : v)
    {
        if (v.find(p.first + C) != v.end())
        {
            count += p.second * v[p.first + C];
        }
    }
    cout << count << endl;

    return 0;
}
