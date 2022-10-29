#include "bits/stdc++.h"

using namespace std;

struct Loop
{
    string name{};
    // -1 no execute, 0 : constant 1:n
    int complex = 0;

    Loop() = default;
    Loop(string name, int complex) : name{name}, complex{complex} {};
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    size_t t;
    cin >> t;
    while (t--)
    {
        size_t l;
        char c;
        //          O    (    1
        //          O    (    n
        cin >> l >> c >> c >> c;
        size_t time_complex;
        if (c == '1')
        {
            time_complex = 0;
        }
        else
        {
            //     ^
            cin >> c;
            cin >> time_complex;
        }
        //     )
        cin >> c;
        size_t max_complex = 0;
        size_t cur_complex = 0;
        unordered_set<string> names;
        stack<Loop> st;
        bool err = false;
        string line;
        getline(cin, line);
        while (l--)
        {
            getline(cin, line);
            stringstream ss{line};
            if (err)
                continue;
            ss >> c;
            if (c == 'E')
            {
                if (st.empty())
                {
                    err = true;
                    continue;
                }

                if (st.top().complex >= 0)
                {
                    max_complex = max(cur_complex, max_complex);
                    cur_complex -= st.top().complex;
                }
                names.erase(st.top().name);
                st.pop();
            }
            else
            {
                string name;
                ss >> name;
                if (names.find(name) != names.end())
                {
                    err = true;
                    continue;
                }

                names.insert(name);

                size_t x, y;
                if (!(ss >> x))
                {
                    ss.clear();
                    ss >> c;
                    x = numeric_limits<size_t>::max();
                }
                if (!(ss >> y))
                {
                    ss.clear();
                    ss >> c;
                    y = numeric_limits<size_t>::max();
                }

                if (!st.empty() && st.top().complex == -1 || x > y)
                {
                    st.push(Loop{name, -1});
                }
                else
                {
                    bool b = x < y && y == numeric_limits<size_t>::max();
                    st.push(Loop{name, b});
                    cur_complex += b;
                }
            }
        }

        if (!st.empty() || err)
        {
            cout << "ERR\n";
        }
        else
        {
            cout << (max_complex == time_complex ? "Yes\n" : "No\n");
        }
    }

    return 0;
}
