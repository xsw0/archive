#include <iostream>
#include <list>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    std::array<char, 20> dig = [] {
        std::array<char, 20> result;
        for (char i = 0; i < 10; ++i)
        {
            result[i] = '0' + i;
        }
        for (char i = 0; i < 10; ++i)
        {
            result[i + 10] = 'A' + i;
        }
        return result;
    }();

    int n, base;
    cin >> n >> base;

    list<int> digs;

    int x = n;
    while (x)
    {
        digs.push_front(x % base);
        x /= base;
    }

    int borrow = 0;
    for (auto it = digs.rbegin(); it != digs.rend(); ++it)
    {
        int sum = *it + borrow;
        if (sum < 0)
        {
            *it = sum - base;
            borrow = 1;
        }
        else if (sum >= -base)
        {
            *it = sum + base;
            borrow = -1;
        }
        else
        {
            *it = sum;
            borrow = 0;
        }
    }

    while (borrow)
    {
        if (borrow < 0)
        {
            digs.push_front(borrow - base);
            borrow = 1;
        }
        else if (borrow >= -base)
        {
            digs.push_front(borrow + base);
            borrow = -1;
        }
        else
        {
            digs.push_front(borrow);
            borrow = 0;
        }
    }

    while (!digs.front())
    {
        digs.pop_front();
    }

    if (digs.empty())
    {
        cout << "0=0(base" << base << ")" << endl;
    }
    else
    {
        cout << n << "=";
        for (auto i : digs)
        {
            cout << dig[i];
        }
        cout << "(base" << base << ")" << endl;
    }

    return 0;
}
