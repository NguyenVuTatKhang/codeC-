#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int parent[MAXN], sz[MAXN];

int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector< pair<int, int> > edge(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edge[i].first >> edge[i].second;
    }

    vector<bool> deleted(m + 1, false);
    vector< vector< pair<int, int> > > queries(m + 2); // luu các truy v?n theo edge index

    for (int i = 0; i < q; ++i) {
        int e, u;
        cin >> e >> u;
        queries[e].push_back(make_pair(i, u));
        deleted[e] = true;
    }

    // Kh?i t?o Union-Find
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    // Thêm t?t c? các c?nh không b? xóa vào d? th?
    for (int i = 1; i <= m; ++i) {
        if (!deleted[i]) {
            int u = edge[i].first;
            int v = edge[i].second;
            unite(u, v);
        }
    }

    vector<int> result(q);

    // Xét t? m -> 1, t?c là thêm l?i các c?nh dã b? xóa ngu?c th?i gian
    for (int i = m; i >= 1; --i) {
        for (size_t j = 0; j < queries[i].size(); ++j) {
            int idx = queries[i][j].first;
            int u = queries[i][j].second;
            result[idx] = sz[find(u)];
        }

        if (deleted[i]) {
            int u = edge[i].first;
            int v = edge[i].second;
            unite(u, v);
        }
    }

    for (int i = 0; i < q; ++i)
        cout << result[i] << "\n";

    return 0;
}

