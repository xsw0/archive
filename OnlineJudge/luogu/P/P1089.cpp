#include <iostream>

using namespace std;

int main()
{
    int now = 0;
    int save = 0;
    for (size_t i = 1; i <= 12; ++i)
    {
        int n;
        cin >> n;
        if (now + 300 < n)
        {
            cout << '-' << i;
            return 0;
        }
        save += (now + 300 - n) / 100;
        now = (now + 300 - n) % 100;
    }
    cout << save * 120 + now << endl;
    return 0;
}
