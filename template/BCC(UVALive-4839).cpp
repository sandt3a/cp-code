// 点双联通分量

#include <bits/stdc++.h>

using namespace std;

const int N = 110005;
const int LOGN = 19;

int n, m;
vector<int> g[N];

int bccno[N];
int bcc_cnt;
vector<int> bcc[N];
bool iscut[N];

struct Edge { int u, v; } stk[N << 3];
int top;
int dfn[N], low[N], dfs_clock;

void dfs(int x, int fa)
{
    low[x] = dfn[x] = ++dfs_clock;
    int child = 0;
    for(auto y: g[x])
    {
        if(!dfn[y])
        {
            child++;
            stk[++top] = (Edge){x, y};
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if(low[y] >= dfn[x])
            {
                iscut[x] = true;
                bcc[++bcc_cnt].clear();
                for(;;)
                {
                    Edge e = stk[top--];
                    if(bccno[e.u] != bcc_cnt) { bcc[bcc_cnt].push_back(e.u); bccno[e.u] = bcc_cnt; }
                    if(bccno[e.v] != bcc_cnt) { bcc[bcc_cnt].push_back(e.v); bccno[e.v] = bcc_cnt; }
                    if(e.u == x && e.v == y) break;
                }
            }
        }
        else if(y != fa && dfn[y] < dfn[x])
        {
            stk[++top] = (Edge){x, y};
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(fa == 0 && child == 1) iscut[x] = false;
}

void find_bcc()
{
    memset(dfn, 0, sizeof(dfn));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            dfs(i, 0);
}

void input()
{
    n += m;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a += m;
        b += m;
        g[a].push_back(i);
        g[b].push_back(i);
        g[i].push_back(a);
        g[i].push_back(b);
    }
}

vector<int> G[N];
int fa[N][LOGN], dep[N];
bool vis[N];

void dfs_G(int x, int p)
{
    vis[x] = 1;
    fa[x][0] = p;
    dep[x] = dep[p] + 1;
    for(int i = 0; fa[x][i]; i++)
        fa[x][i + 1] = fa[fa[x][i]][i];
    for(auto y: G[x])
        if(y != p)
            dfs_G(y, x);
}

int lca(int x, int y)
{
    if(dep[x] < dep[y])
        swap(x, y);
    for(int i = LOGN - 1; i >= 0; i--)
        if(dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if(x == y) return x;
    for(int i = LOGN - 1; i >= 0; i--)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void prepare_lca()
{
    for(int i = 1; i <= n; i++)
        if(iscut[i])
            bccno[i] = ++bcc_cnt;
//  for(int i = 1; i <= n; i++)
//      printf("%3d%c", iscut[i], " \n"[i == n]);
//  for(int i = 1; i <= n; i++)
//  {
//      printf("%3d%c", bccno[i], " \n"[i == n]);
//  }
    for(int i = 1; i <= bcc_cnt; i++)
        G[i].clear();
    for(int x = 1; x <= n; x++)
    {
        for(auto y: g[x])
        {
            if(bccno[x] != bccno[y])
            {
                G[bccno[x]].push_back(bccno[y]);
                G[bccno[y]].push_back(bccno[x]);
            }
        }
    }
    for(int i = 1; i <= bcc_cnt; i++)
    {
        sort(G[i].begin(), G[i].end());
        G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
    }
    memset(fa, 0, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= bcc_cnt; i++)
        if(!vis[i]) dfs_G(i, 0);
}

void solve()
{
    find_bcc();
    prepare_lca();
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a = bccno[a];
        b = bccno[b];
        printf("%d\n", (dep[a] + dep[b] - dep[lca(a, b)] * 2) / 2);
    }
}

int main()
{
    while(scanf("%d%d",  &n, &m) == 2)
    {
        if(n == 0 && m == 0) break;
        input();
        solve();
    }
    return 0;
}
