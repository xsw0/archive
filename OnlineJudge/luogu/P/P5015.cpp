#include <iostream>

using namespace std;

int main()
{
    char c;
    size_t count = 0;
    while (cin >> c)
    {
        ++count;
    }
    cout << count << endl;

    return 0;
}
