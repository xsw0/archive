#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t M;
    cin >> M;

    size_t prevprev = 0;
    size_t prev = 1;
    size_t index = 2;
    while (true)
    {
        size_t sum = (prevprev + prev) % M;
        if (sum == 0 && prev == 1)
            break;
        prevprev = prev;
        prev = sum;
        ++index;
    }
    cout << index << endl;

    return 0;
}
