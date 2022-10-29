#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

size_t moder = 80112002;

class modNum
{
public:
    size_t n;
    modNum(size_t n = 0) : n(n % moder){};
    modNum operator+(const modNum &other) const
    {
        return ((n % moder) + (other.n % moder)) % moder;
    }
    modNum operator*(const modNum &other) const
    {
        return ((n % moder) * (other.n % moder)) % moder;
    }
    operator size_t() const
    {
        return n % moder;
    };
};

int main()
{
    unordered_map<size_t, unordered_set<size_t>> mus;
    unordered_set<size_t> creator;
    unordered_set<size_t> non_creator;
    size_t N, M;
    cin >> N >> M;
    for (size_t i = 0; i < M; ++i)
    {
        size_t a, b;
        cin >> a >> b;
        --a, --b;
        non_creator.insert(b);
        creator.erase(b);
        if (non_creator.find(a) == non_creator.end())
        {
            creator.insert(a);
        }
        mus[a].insert(b);
    }

    unordered_map<size_t, size_t> table;
    function<size_t(size_t)> f = [&](size_t n) -> size_t {
        if (table.find(n) == table.end())
        {
            if (mus.find(n) == mus.end())
            {
                table[n] = 1;
            }
            else
            {
                modNum result = 0;
                for (auto i : mus[n])
                {
                    result = result + modNum(f(i));
                }
                table[n] = result;
            }
        }
        return table[n];
    };

    modNum result = 0;
    for (auto i : creator)
    {
        result = result + modNum(f(i));
    }
    cout << result << endl;

    return 0;
}
