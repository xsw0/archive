#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int n;
    int count, cost;
    int minimum = std::numeric_limits<int>::max();
    cin >> n;
    for (size_t i = 0; i < 3; ++i)
    {
        cin >> count >> cost;
        minimum = min((n + count - 1) / count * cost, minimum);
    }
    cout << minimum << endl;
    return 0;
}
