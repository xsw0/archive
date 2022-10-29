#include "bits/stdc++.h"

using namespace std;

array<array<array<int64_t, 21>, 21>, 21> arr{};
array<array<array<bool, 21>, 21>, 21> have{};

int64_t w(int64_t a, int64_t b, int64_t c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (!have[a][b][c])
    {
        have[a][b][c] = true;
        if (a < b && b < c)
            arr[a][b][c] =
                w(a, b, c - 1) +
                w(a, b - 1, c - 1) -
                w(a, b - 1, c);
        else
            arr[a][b][c] =
                w(a - 1, b, c) +
                w(a - 1, b - 1, c) +
                w(a - 1, b, c - 1) -
                w(a - 1, b - 1, c - 1);
    }
    return arr[a][b][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t a, b, c;
    while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1))
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }

    return 0;
}
