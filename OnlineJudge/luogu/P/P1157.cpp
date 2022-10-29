#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    int c, r;
    cin >> c >> r;
    vector<int> v;
    v.reserve(r);
    function<void(int minimum, int maximum, int count)> C = [&](int minimum, int maximum, int count) -> void {
        if (maximum - minimum + 1 >= count)
        {
            if (count == 0)
            {
                for (auto i : v)
                {
                    cout << setw(3) << i;
                }
                cout << '\n';
            }
            else
            {
                v.push_back(minimum);
                C(minimum + 1, maximum, count - 1);
                v.pop_back();
                C(minimum + 1, maximum, count);
            }
        }
    };
    C(1, c, r);
    cout << flush;
    return 0;
}
