#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<size_t, bool> um{{0, false}, {1, false}};

bool isPrime(size_t n)
{
    if (um.find(n) == um.end())
    {
        for (size_t i = 2; i < n; ++i)
        {
            if (n % i == 0)
            {
                um[n] = false;
                return um[n];
            }
        }
        um[n] = true;
    }
    return um[n];
}

size_t count(vector<size_t>::const_iterator start,
             vector<size_t>::const_iterator last,
             size_t k,
             size_t sum = 0)
{
    if (k == 0)
    {
        if (isPrime(sum))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    size_t result = 0;
    result += count(next(start), last, k - 1, sum + *start);
    if (distance(start, last) > k)
    {
        result += count(next(start), last, k, sum);
    }
    return result;
}

int main()
{
    size_t n, k;
    cin >> n >> k;
    vector<size_t> v;
    v.reserve(n);

    for (size_t i = 0; i < n; ++i)
    {
        size_t a;
        cin >> a;
        v.push_back(a);
    }

    cout << count(v.cbegin(), v.cend(), k);
    return 0;
}
