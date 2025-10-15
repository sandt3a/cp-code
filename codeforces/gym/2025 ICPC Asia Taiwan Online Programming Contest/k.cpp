#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int inf = 0x3f3f3f3f;

struct Graph {
    struct Edge {
        int to;
        int flow;
        int cap;
        int nxt;
    };

    vector<int> head;
    vector<Edge> edge;

    Graph() {}
    Graph(int n) {
        init(n);
    }

    void init(int n) {
        head.assign(n, -1);
        edge.clear();
    }

    void add_edge(int a, int b, int c) {
        edge.push_back({b, 0, c, head[a]});
        head[a] = (int)edge.size() - 1;
        edge.push_back({a, 0, 0, head[b]});
        head[b] = (int)edge.size() - 1;
    }

    vector<int> cur;
    vector<int> h;

    bool bfs(int s, int t) {
        h.assign(head.size(), -1);
        queue<int> q;
        h[t] = 0;
        q.push(t);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = head[x]; ~i; i = edge[i].nxt) {
                auto &e = edge[i];
                auto &re = edge[i^1];
                if (re.flow < re.cap && h[e.to] == -1) {
                    h[e.to] = h[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return h[s] != -1;
    }

    int dfs(int x, int t, int f) {
        if (x == t || f == 0) {
            return f;
        }
        int ff = f;
        for (auto &i = cur[x]; ~i; i = edge[i].nxt) {
            auto &e = edge[i];
            auto &re = edge[i^1];
            if (e.flow < e.cap && h[e.to] == h[x] - 1) {
                int a = dfs(e.to, t, min(e.cap - e.flow, ff));
                e.flow += a;
                re.flow -= a;
                ff -= a;
                if (ff == 0) {
                    return f;
                }
            }
        }
        return f - ff;
    }

    int max_flow(int s, int t) {
        int f = 0;
        while (bfs(s, t)) {
            cur = head;
            f += dfs(s, t, inf);
        }
        return f;
    }
};

void solve()
{
    int n;
    cin >> n;

    int need = 0;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                need++;
            }
        }
    }

    int id = 0;
    int src = id++;
    int dst = id++;
    vector<int> row(n);
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        row[i] = id++;
        col[i] = id++;
    }
    auto node = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            node[i][j] = id++;
        }
    }

    Graph g(id);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 1) {
                g.add_edge(src, node[i][j], a[i][j] - 1);
                g.add_edge(node[i][j], row[i], inf);
                g.add_edge(node[i][j], col[j], inf);
            } else if (a[i][j] == 0) {
                g.add_edge(node[i][j], dst, 1);
                g.add_edge(row[i], node[i][j], inf);
                g.add_edge(col[j], node[i][j], inf);
            }
        }
    }

    int f = g.max_flow(src, dst);
    int ans = f + (need - f) * 2;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
