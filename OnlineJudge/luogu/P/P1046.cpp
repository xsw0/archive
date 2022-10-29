#include <iostream>
#include <array>

using namespace std;

int main()
{
    std::array<int, 10> arr;
    for (size_t i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    int r;
    cin >> r;
    r += 30;
    int count = 0;
    for (auto i : arr)
    {
        if (i <= r)
            ++count;
    }
    cout << count << endl;

    return 0;
}
