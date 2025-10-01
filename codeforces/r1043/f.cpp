#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> e(n);
    vector<array<int, 2>> edge(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
        edge[i] = {x, y};
    }

    vector<int> dfn(n, -1), low(n);
    int dfs_clock = 0;
    vector<int> mark(n, -1);
    vector<int> ok(n);

    std::function<void(int, int)> dfs = [&](int x, int p) -> void {
        dfn[x] = low[x] = dfs_clock++;
        ok[x] = (x == n - 1);
        for (auto [y, eid]: e[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                dfs(y, x);
                ok[x] |= ok[y];
                low[x] = min(low[x], low[y]);
                if (low[y] > dfn[x] && ok[y]) {
                    // cout<<"bridge:"<<x<<" "<<y<<" id="<<eid<<endl;
                    if (mark[x] == -1 || mark[x] > eid) {
                        mark[x] = eid;
                    }
                    if (mark[y] == -1 || mark[y] > eid) {
                        mark[y] = eid;
                    }
                }
            } else {
                low[x] = min(low[x], dfn[y]);
                ok[x] |= ok[y];
            }
        }
        // cout<<"x="<<x<<" dfn="<<dfn[x]<<" low="<<low[x]<<endl;
    };

    dfs(0, -1);

    vector<array<int, 2>> dis(n, {-1, -1});

    [&]() {
        queue<int> q;
        vector<int> inq(n);

        for (int i = 0; i < n; i++) {
            if (mark[i] != -1) {
                dis[i] = {0, mark[i]};
                q.push(i);
                inq[i] = true;
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            inq[x] = false;

            auto [d, eid] = dis[x];
            array<int, 2> nd = {d + 1, eid};
            for (auto [y, _]: e[x]) {
                if (dis[y][0] == -1 || dis[y] > nd) {
                    dis[y] = nd;
                    if (!inq[y]) {
                        inq[y] = true;
                        q.push(y);
                    }
                }
            }
        }
    } ();

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        auto [d, eid] = dis[x];
        if (d == -1) {
            eid = -1;
        } else {
            eid++;
        }
        cout << eid << " \n"[q == 0];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
