#include "bits/stdc++.h"

using namespace std;

struct Tree {
    unique_ptr<Tree> left = nullptr;
    unique_ptr<Tree> right = nullptr;
    size_t l;
    size_t r;
    int64_t value = 0;

    int64_t get(size_t first, size_t last) {}

    void add(size_t first, size_t last, int64_t value) {
        if (first <= l && last >= r) {
            this->value += (last - first) * value;
        } else {
            left->add(first, last, value);
            right->add(first, last, value);
        }
    }

    Tree(const vector<int64_t> &v, size_t first, size_t last)
        : l{first}, r{last} {
        size_t size = r - l;
        if (l + 1 == r) {
            value = v[l];
        } else {
            auto mid = l + size / 2;
            left = std::make_unique<Tree>(v, first, mid);
            right = std::make_unique<Tree>(v, mid, last);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
