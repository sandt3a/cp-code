// O(n + q) method by ChatGPT
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> t(n + 1), indeg(n + 1);
    vector<vector<int>> rev(n + 1);

    for (int u = 1; u <= n; ++u) {
        cin >> t[u];
        ++indeg[t[u]];
        rev[t[u]].push_back(u);
    }

    vector<vector<pair<int, int>>> queries(n + 1);

    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        queries[x].emplace_back(k, i);
    }

    queue<int> que;

    for (int u = 1; u <= n; ++u) {
        if (indeg[u] == 0) {
            que.push(u);
        }
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        if (--indeg[t[u]] == 0) {
            que.push(t[u]);
        }
    }

    vector<char> used(n + 1);
    vector<int> ptr(n + 1), ans(q), path;
    path.reserve(n);

    for (int s = 1; s <= n; ++s) {
        if (indeg[s] == 0 || used[s]) {
            continue;
        }

        vector<int> cycle;
        int u = s;

        do {
            cycle.push_back(u);
            used[u] = true;
            u = t[u];
        } while (u != s);

        int len = static_cast<int>(cycle.size());

        for (int p = 0; p < len; ++p) {
            path.push_back(cycle[p]);

            while (!path.empty()) {
                int v = path.back();

                if (ptr[v] == 0) {
                    int d = static_cast<int>(path.size()) - 1;

                    for (auto [k, id] : queries[v]) {
                        if (k <= d) {
                            ans[id] = path[d - k];
                        } else {
                            ans[id] = cycle[(p + k - d) % len];
                        }
                    }
                }

                if (ptr[v] == static_cast<int>(rev[v].size())) {
                    path.pop_back();
                } else {
                    int w = rev[v][ptr[v]++];

                    if (indeg[w] == 0) {
                        path.push_back(w);
                    }
                }
            }
        }
    }

    for (int x : ans) {
        cout << x << '\n';
    }
}
