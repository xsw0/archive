#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    // vector<double> S = {0.0};
    // double i = 1.0;
    // while (S.back() <= 15.0)
    // {
    //     S.push_back(S.back() + 1.0 / i);
    //     i += 1.0;
    // }
    // for (double i = 1; i < 15.5; i += 1.0)
    // {
    //     cout << upper_bound(S.begin(), S.end(), i) - S.begin() << ',' << endl;
    // }
    array<int, 16> arr = {1, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, 91380, 248397, 675214, 1835421};
    int n;
    cin >> n;
    cout << arr[n] << endl;

    return 0;
}
