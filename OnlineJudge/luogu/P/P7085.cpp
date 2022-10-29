#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double W, H, w, h;
    cin >> W >> H >> w >> h;

    int row = H / (h * 2);

    if (h + row * (h * 2) <= H) ++row;

    int col = W / (w * 2);

    if (w + col * (w * 2) <= W) ++col;

    cout << row * col << endl;

    return 0;
}
