#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    constexpr int L = 20;
    vector<int> dep(n + 1);
    vector<int> fa(n + 1);
    vector<array<int, L>> f(n + 1);

    auto dfs = [&](this auto &&self, int x, int p) -> void {
        fa[x] = p;
        f[x][0] = p;
        for (int i = 0; i + 1 < L; i++) {
            f[x][i + 1] = f[f[x][i]][i];
        }
        dep[x] = dep[p] + 1;
        for (auto y: e[x]) {
            if (y == p) continue;
            self(y, x);
        }
    };

    dfs(1, 0);

    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        int d = dep[x] - dep[y];
        for (int i = L - 1; i >= 0; i--) {
            if (d >> i & 1) {
                x = f[x][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = L - 1; i >= 0; i--) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    };

    int ans = dep[n] - dep[1];
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;

        int z = lca(v, n);
        if (z != 1) {
            ans = max(ans, dep[n] + dep[v] - 2 * dep[z] + 1);
        }
    }
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
