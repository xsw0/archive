#include <iostream>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    {
        int cof;
        cin >> cof;
        switch (cof)
        {
        case 1:
            cout << "x^" << n;
            break;
        case -1:
            cout << "-x^" << n;
            break;
        default:
            cout << cof << "x^" << n;
            break;
        }
        --n;
    }
    for (; n > 1; --n)
    {
        int cof;
        cin >> cof;
        switch (cof)
        {
        case 1:
            cout << "+x^" << n;
            break;
        case -1:
            cout << "-x^" << n;
            break;
        default:
            cout << showpos << cof << "x^" << n;
            break;
        case 0:
            break;
        }
    }
    {
        int cof;
        cin >> cof;
        switch (cof)
        {
        case 1:
            cout << "+x";
            break;
        case -1:
            cout << "-x";
            break;
        default:
            cout << showpos << cof << "x";
            break;
        case 0:
            break;
        }
    }
    {
        int cof;
        cin >> cof;
        if (cof != 0)
        {
            cout << showpos << cof;
        }
    }
    cout << endl;
    return 0;
}
