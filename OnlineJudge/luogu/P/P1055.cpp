#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ISBN;
    cin >> ISBN;
    // assert(ISBN.size() == 13);
    size_t check = 0;
    size_t j = 1;
    for (size_t i = 0; i < 11; ++i)
    {
        switch (i)
        {
        case 1:
        case 5:
            break;
        default:
            check += j * (ISBN[i] - '0');
            ++j;
            break;
        }
    }
    check %= 11;

    if (check == ISBN[12] - '0' || (check == 10 && ISBN[12] == 'X'))
    {
        cout << "Right" << endl;
    }
    else
    {
        cout << ISBN.substr(0, 12);
        if (check == 10)
        {
            cout << 'X' << endl;
        }
        else
        {
            cout << check << endl;
        }
    }

    return 0;
}
