#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << 1 << endl;
        return 0;
    }

    constexpr unsigned mod = 100003;

    vector<unsigned> v(K, 0);

    v[0] = 1;
    unsigned sum = 1;
    for (size_t i = 1; i <= N; ++i) {
        size_t index = i % K;
        size_t next = sum;

        sum += mod + next - v[index];
        sum %= mod;

        v[index] = next;
    }

    cout << v[N % K] << endl;

    return 0;
}
