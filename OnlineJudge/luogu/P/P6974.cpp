#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint64_t n;
    int q;
    cin >> n >> q;

    vector<bool> rows(n + 1);
    vector<bool> cols(n + 1);

    uint64_t sum_of_rows = (1 + n) * n / 2;
    uint64_t sum_of_cols = (1 + n) * n / 2;

    uint64_t num_of_rows = n;
    uint64_t num_of_cols = n;

    while (q--)
    {
        char c;
        cin >> c;
        size_t m;
        cin >> m;
        if (c == 'R')
        {
            if (rows[m])
            {
                cout << "0\n";
            }
            else
            {
                cout << sum_of_cols + m * num_of_cols << "\n";
                rows[m] = true;
                sum_of_rows -= m;
                --num_of_rows;
            }
        }
        else
        {
            if (cols[m])
            {
                cout << "0\n";
            }
            else
            {
                cout << sum_of_rows + m * num_of_rows << "\n";
                cols[m] = true;
                sum_of_cols -= m;
                --num_of_cols;
            }
        }
    }

    return 0;
}
