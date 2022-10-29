#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pkg
{
    size_t weight;
    size_t value;
};

vector<Pkg> v;
vector<size_t> maximum;

int main()
{
    size_t T, M;
    cin >> T >> M;
    v.resize(M);
    maximum.resize(T + 1);
    for (size_t i = 0; i < M; ++i)
    {
        cin >> v[i].weight >> v[i].value;
    }

    for (size_t i = 0; i < M; ++i)
    {
        if (v[i].weight <= T)
        {
            for (size_t j = T - v[i].weight; j > 0; --j)
            {
                maximum[j + v[i].weight] = max(maximum[j + v[i].weight], maximum[j] + v[i].value);
            }
            maximum[v[i].weight] = max(maximum[v[i].weight], maximum[0] + v[i].value);
        }
    }

    cout << *max_element(maximum.begin(), maximum.end()) << endl;

    return 0;
}
