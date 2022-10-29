#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int duplicate = n;
    int repeat = 1;
    int count = 0;
    while (duplicate)
    {
        int period = repeat * 10;
        int size = n - repeat + 1;
        count += (size / period) * repeat;
        if (x == 0)
        {
            if ((size % period) / repeat == 9)
            {
                count += (size % period) - repeat * 9;
            }
        }
        else if ((size % period) / repeat >= x)
        {
            count += repeat;
        }
        else if ((size % period) / repeat == x - 1)
        {
            count += (size % period) - repeat * (x - 1);
        }
        repeat *= 10;
        duplicate /= 10;
    }

    cout << count << endl;

    return 0;
}
