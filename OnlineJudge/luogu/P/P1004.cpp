#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    size_t N, row, col;
    cin >> N;
    int value;
    vector<vector<int>> v(N, vector(N, 0));
    vector<vector<int>> largest(N, vector(N, 0));
    vector<vector<int>> largest2(N, vector(N, 0));
    while (cin >> row >> col >> value && row != 0)
    {
        v[row - 1][col - 1] = value;
    }

    return 0;
}
