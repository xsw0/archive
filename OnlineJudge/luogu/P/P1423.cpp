#include <iostream>

using namespace std;

int main()
{
    double input;
    cin >> input;
    double x = 2;
    size_t i = 1;
    while (input > x)
    {
        input -= x;
        x *= 0.98;
        ++i;
    }
    cout << i << endl;
    return 0;
}
