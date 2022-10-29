#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> left;
    set<int> right;
    left.insert(0);
    int l, m;
    cin >> l >> m;
    right.insert(l + 1);
    for (int i = 0; i < m && !left.empty() && !right.empty(); i++)
    {
        int a, b;
        cin >> a >> b;
        ++b;
        auto ll = left.lower_bound(a);
        auto lr = left.lower_bound(b);
        auto rl = right.upper_bound(a);
        auto rr = right.upper_bound(b);
        left.erase(ll, lr);
        right.erase(rl, rr);
        if ((lr == left.end()) !=
                (rr == right.end()) ||
            (lr != left.end() &&
             rr != right.end() &&
             *lr >= *rr))
        {
            left.insert(b);
        }
        if ((ll == left.begin()) !=
                (rl == right.begin()) ||
            (ll != left.begin() &&
             rl != right.begin() &&
             *prev(ll) >= *prev(rl)))
        {
            right.insert(a);
        }
    }
    int count = 0;
    for (auto itl = left.cbegin(), itr = right.cbegin();
         itl != left.cend();
         ++itl, ++itr)
    {
        count += *itr - *itl;
    }
    cout << count << endl;
    return 0;
}