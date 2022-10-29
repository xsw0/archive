#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int minDiagonals = 0, maxDiagonals = 4471;
    while (minDiagonals != maxDiagonals)
    {
        int mid = (minDiagonals + maxDiagonals + 1) / 2;
        if ((mid * mid + mid) / 2 < n)
        {
            minDiagonals = mid;
        }
        else
        {
            maxDiagonals = mid - 1;
        }
    }
    int diagonals = minDiagonals;
    int index = n - (diagonals * diagonals + diagonals) / 2;
    if (diagonals % 2 == 0)
    {
        cout << diagonals + 2 - index << '/' << index << endl;
    }
    else
    {
        cout << index << '/' << diagonals + 2 - index << endl;
    }

    return 0;
}
