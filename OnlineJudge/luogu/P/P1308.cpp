#include "bits/stdc++.h"

using namespace std;

bool isSame(const string &lhs, const string &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i)
    {
        if (tolower(lhs[i]) != tolower(rhs[i]))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string match, word;
    getline(cin, match);

    size_t index = 0;
    unsigned count = 0;
    int first = -1;

    int start = 0;

    char c;
    while (cin.get(c))
    {
        if (c == ' ' || c == '\n')
        {
            if (isSame(word, match))
            {
                if (first < 0)
                    first = start;
                ++count;
            }
            word.clear();
            start = index + 1;
        }
        else
        {
            word.push_back(c);
        }
        ++index;
    }

    if (first < 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << count << " " << first << "\n";
    }
    return 0;
}
