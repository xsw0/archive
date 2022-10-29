#include "bits/stdc++.h"

using namespace std;

double a, b, c, d;

double f(double x) { return ((a * x + b) * x + c) * x + d; }

double count(double l, double r) {
    auto mid = l + (r - l) / 2;
    if (abs(f(mid)) < 1.0 / 1024.0) {
        return mid;
    } else {
        return f(l) * f(mid) < 0 ? count(l, mid) : count(mid, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c >> d;

    vector<double> root;
    root.reserve(3);

    double n = -100.0;
    while (n < 100.0) {
        if (f(n) == 0) {
            root.push_back(n);
            n += 0.99;
        } else if (f(n) * f(n + 1) <= 0) {
            root.push_back(count(n, n + 1));
            n = root.back() + 0.99;
        } else {
            n += 0.99;
        }
    }
    for (auto r : root) {
        cout << fixed << setprecision(2) << r << " ";
    }
    cout << endl;

    return 0;
}
