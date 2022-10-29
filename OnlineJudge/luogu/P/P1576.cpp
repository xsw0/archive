#include "bits/stdc++.h"

using namespace std;

struct Edge {
    size_t x = 0;
    size_t y = 0;
    double value = 0;
    Edge(size_t x, size_t y, double value) : x{x}, y{y}, value{value} {}
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    auto cmp = [](const Edge &lhs, const Edge &rhs) {
        return lhs.value < rhs.value;
    };
    vector<vector<Edge>> graph(n);
    while (m--) {
        size_t x, y;
        double z;
        cin >> x >> y >> z;
        --x, --y;
        z = 100 - z;
        z /= 100;
        graph[x].emplace_back(x, y, z);
        graph[y].emplace_back(y, x, z);
    }
    size_t a, b;
    cin >> a >> b;
    --a, --b;

    priority_queue<Edge, std::vector<Edge>, decltype(cmp)> edges(cmp);

    for (auto &edge : graph[a]) {
        edges.push(edge);
    }

    vector<double> values(n);
    values[a] = 1;
    while (values[b] == 0.0) {
        auto top = edges.top();
        edges.pop();
        if (values[top.y] == 0.0) {
            values[top.y] = top.value;
            for (auto &edge : graph[top.y]) {
                edges.push(Edge{top.y, edge.y, top.value * edge.value});
            }
        }
    }

    cout << fixed << setprecision(8) << 100.0 / values[b] << endl;

    return 0;
}
