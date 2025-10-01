#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;

struct Graph
{
    int n, m;
    int head[MAXN];
    int u[MAXM], v[MAXM], w[MAXM], nxt[MAXM];

    void init(int _n) {
        n = _n; m = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int a, int b, int c) {
        u[m] = a, v[m] = b, w[m] = c, nxt[m] = head[a], head[a] = m++;
    }
};

struct DominatorTree
{
    int n, s, cnt;
    int dfn[MAXN], id[MAXN], pa[MAXN], semi[MAXN], idom[MAXN], p[MAXN], mn[MAXN];
    vector<int> e[MAXN], dom[MAXN], be[MAXN];

    void insert(int x, int y) {
        e[x].push_back(y);
    }
    void dfs(int x) {
        dfn[x] = ++cnt;
        id[cnt] = x;
        for (auto i: e[x]) {
            if (!dfn[i]) dfs(i), pa[dfn[i]] = dfn[x];
            be[dfn[i]].push_back(dfn[x]);
        }
    }
    int get(int x) {
        if (p[x] != p[p[x]]) {
            if (semi[mn[x]] > semi[get(p[x])]) mn[x] = get(p[x]);
            p[x] = p[p[x]];
        }
        return mn[x];
    }
    void LT() {
        for (int i = cnt; i > 1; i--) {
            for (auto j: be[i])
                semi[i] = min(semi[i], semi[get(j)]);
            dom[semi[i]].push_back(i);
            int x = p[i] = pa[i];
            for (auto j: dom[x])
                idom[j] = (semi[get(j)] < x ? get(j) : x);
            dom[x].clear();
        }
        for (int i = 2; i <= cnt; i++) {
            if (idom[i] != semi[i]) idom[i] = idom[idom[i]];
            dom[id[idom[i]]].push_back(id[i]);
        }
    }
    void build(int _n, int _s) {
        n = _n, s = _s;
        for (int i = 1; i <= n; i++)
            dfn[i] = 0, dom[i].clear(), be[i].clear(), p[i] = mn[i] = semi[i] = i;
        cnt = 0, dfs(s), LT();
    }
};

int n, m;
Graph g;
DominatorTree d;
int ans[MAXN];
int sz[MAXN];

void dfs(int x) {
    sz[x] = 1;
    for (auto y: d.dom[x]) {
        dfs(y);
        sz[x] += sz[y];
    }
}

void dijkstra()
{
    typedef pair<long long, int> node;
    priority_queue<node, vector<node>, greater<node>> q;
    static long long dis[MAXN];
    static bool vis[MAXN];

    memset(dis, 0x3f, sizeof(dis));

    q.push({dis[1] = 0, 1});
    while (!q.empty()) {
        int x = q.top().second; q.pop();
        if (vis[x]) continue; vis[x] = 1;
        for (int i = g.head[x]; ~i; i = g.nxt[i]) {
            int y = g.v[i];
            if (dis[y] > dis[x] + g.w[i]) {
                q.push({dis[y] = dis[x] + g.w[i], y});
            }
        }
    }
    // for (int i = 1; i <= n; i++)
        // printf("%d%c", dis[i], " \n"[i == n]);
    static int deg[MAXN];
    for (int i = 0; i < g.m; i++) {
        int x = g.u[i];
        int y = g.v[i];
        if (dis[x] + g.w[i] == dis[y]) {
            d.insert(x, y);
            deg[y]++;
        }
    }
    d.build(n, 1);
    dfs(1);
    for (int i = 0; i < g.m; i++) {
        int x = g.u[i];
        int y = g.v[i];
        if (dis[x] + g.w[i] == dis[y]) {
            if (deg[y] == 1) {
                ans[i/2 + 1] += sz[y];
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    g.init(n);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g.addedge(a, b, c);
        g.addedge(b, a, c);
    }

    dijkstra();

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
