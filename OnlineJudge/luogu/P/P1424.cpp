#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    size_t x, n;
    cin >> x >> n;
    unordered_set<size_t> us;
    for (size_t i = 0; i < n % 7; ++i)
    {
        us.insert((x + i - 1) % 7 + 1);
    }
    us.erase(6);
    us.erase(7);
    cout << (n / 7 * 5 + us.size()) * 250 << endl;

    return 0;
}
