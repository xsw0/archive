#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int64_t a1, a2, n;
    cin >> a1 >> a2 >> n;
    int64_t d = a2 - a1;
    int64_t an = a1 + (n - 1) * d;
    cout << (a1 + an) * n / 2 << endl;

    return 0;
}
