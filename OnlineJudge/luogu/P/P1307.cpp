#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if (n < 0)
        {
            cout << '-';
            n = -n;
        }
        list<int> l;
        while (n > 0)
        {
            l.push_back(n % 10);
            n /= 10;
        }
        while (l.front() == 0)
        {
            l.pop_front();
        }
        for (auto i : l)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
