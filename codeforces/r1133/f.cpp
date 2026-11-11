#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    int w, x, y, z;
    cin >> w >> x >> y >> z;

    const int N = 2*n + 3*m + 5;
    vector<vector<int>> g(N);

    map<pair<int, int>, int> mp;
    int id = 0;
    auto get = [&](auto pr) -> int {
        if (mp.contains(pr)) {
            return mp[pr];
        }
        return mp[pr] = id++;
    };

    auto add_edge = [&](auto a, auto b) -> void {
        int u = get(a);
        int v = get(b);
        g[u].push_back(v);
        g[v].push_back(u);
    };

    vector<array<int, 2>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    // for (auto [x, y]: edges|views::enumerate) {
    //     println("{},{}",x,y);
    // }

    for (auto [u, v]: edges) {
        add_edge(pair(w, u), pair(w, v));
        add_edge(pair(y, u), pair(y, v));
        add_edge(pair(u, u), pair(u, v));
        add_edge(pair(v, u), pair(v, v));
        add_edge(pair(v, u), pair(u, v));
    }

    auto bfs = [&](int s) -> vector<int> {
        vector<int> dis(N, -1);
        dis[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v: g[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis;
    };

    auto dis = bfs(get(pair(w, x)));
    int ans = dis[get(pair(y, z))];
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
