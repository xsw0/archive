#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    for (size_t i = 0; i != n; ++i)
        cin >> A[i];
    for (size_t i = 0; i != n; ++i)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int maximum = 0;

    auto b = B.cbegin();
    for (auto a = A.cbegin(); a != A.cend(); ++a) {
        while (b != B.cend() && *b < *a)
            ++b;
        int minimum = numeric_limits<int>::max();
        if (b != B.cbegin() && *a - *prev(b) < minimum)
            minimum = *a - *prev(b);
        if (b != B.cend() && *b - *a < minimum)
            minimum = *b - *a;
        if (minimum > maximum)
            maximum = minimum;
    }
    cout << maximum << endl;

    return 0;
}
