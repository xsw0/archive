#include "bits/stdc++.h"

using namespace std;

struct Person {
    bool a;
    string name;
    Person(){};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    vector<Person> people;
    people.resize(n);
    for (size_t i = 0; i < n; i++) {
        cin >> people[i].a >> people[i].name;
    }
    size_t index = 0;
    while (m--) {
        bool a;
        size_t s;
        cin >> a >> s;
        index += people[index].a == a ? n - s : s;
        index %= n;
    }
    cout << people[index].name << endl;

    return 0;
}
