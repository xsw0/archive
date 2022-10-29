#include <iostream>
#include <unordered_map>
#include <functional>

using namespace std;

int main()
{
    unordered_map<int, int> um;
    function<int(int)> compute = [&](int n) -> int {
        if (um.find(n) == um.end())
        {
            int sum = 1;
            for (int i = 1; i <= n / 2; ++i)
            {
                sum += compute(i);
            }
            um[n] = sum;
            return sum;
        }
        else
        {
            return um[n];
        }
    };
    int n;
    cin >> n;
    cout << compute(n) << endl;
    return 0;
}
