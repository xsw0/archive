#include "bits/stdc++.h"

using namespace std;

size_t gcd(size_t a, size_t b) { return a ? gcd(b % a, a) : b; }

size_t lcm(size_t a, size_t b) { return a * b / gcd(a, b); }

array<array<bool, 5>, 5> win{{
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0},
}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, na, nb;
    cin >> n >> na >> nb;
    vector<size_t> a, b;
    a.reserve(na);
    b.reserve(nb);
    for (size_t i = 0; i < na; ++i) {
        size_t t;
        cin >> t;
        a.push_back(t);
    }
    for (size_t i = 0; i < nb; ++i) {
        size_t t;
        cin >> t;
        b.push_back(t);
    }

    auto LCM = lcm(na, nb);
    size_t ra = 0;
    size_t rb = 0;
    if (n < LCM) {
        for (size_t i = 0; i < n; i++) {
            ra += win[a[i % na]][b[i % nb]];
            rb += win[b[i % nb]][a[i % na]];
        }
    } else {
        size_t i = 0;
        size_t rem = n % LCM;
        for (; i < rem; ++i) {
            ra += win[a[i % na]][b[i % nb]];
            rb += win[b[i % nb]][a[i % na]];
        }
        size_t rem_a = ra;
        size_t rem_b = rb;
        for (; i < LCM; ++i) {
            ra += win[a[i % na]][b[i % nb]];
            rb += win[b[i % nb]][a[i % na]];
        }
        ra *= n / LCM;
        rb *= n / LCM;
        ra += rem_a;
        rb += rem_b;
    }

    cout << ra << " " << rb << endl;
    return 0;
}
