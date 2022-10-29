#include <iostream>

using namespace std;

int main()
{
    int day = 0, h = 8;
    for (int i = 1; i <= 7; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a + b > h)
        {
            day = i;
            h = a + b;
        }
    }
    cout << day << endl;
    return 0;
}
