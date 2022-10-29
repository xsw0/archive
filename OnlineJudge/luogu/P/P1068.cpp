#include "bits/stdc++.h"

using namespace std;

struct Person
{
    int id;
    int score;
    Person(int id = 0, int score = 0) : id{id}, score{score} {}
    bool operator<(const Person &rhs) const
    {
        return score < rhs.score || score == rhs.score && id > rhs.id;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    m = m * 3 / 2;
    vector<Person> v;
    v.resize(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> v[i].id >> v[i].score;
    }

    sort(v.rbegin(), v.rend());

    int limit = v[m - 1].score;
    size_t last = m;
    while (last != n && v[last].score >= limit) ++last;

    cout << limit << " " << last << "\n";
    for (size_t i = 0; i < last; ++i)
    {
        cout << v[i].id << " " << v[i].score << "\n";
    }

    return 0;
}
