#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;  
    cin >> n;

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (n % 2 == 0) {
        cout << n + 1 << "\n";
        return;
    }

    for (auto [k, v]: vector<array<int, 2>>{{n, n}, {n + 1, (n+1)/2}, {n + 2, 1}}) {
        // cout<<"k="<<k<<" v="<<v<<endl;
        vector<int> fa(n + 1);
        vector<int> dep(n + 1);
        vector<int> sz(n + 1);
        vector<int> top(n + 1);
        vector<int> son(n + 1);
        [&](this auto &&self, int x, int p) -> void {
            fa[x] = p;
            sz[x] = 1;
            dep[x] = dep[p] + 1;
            for (auto y: e[x]) {
                if (y == p) continue;
                self(y, x);
                sz[x] += sz[y];
            }
        }(v, 0);
        [&](this auto &&self, int x, int p) -> void {
            top[x] = p;
            son[x] = 0;
            assert(sz[0] == 0);
            for (auto y: e[x]) {
                if (y == fa[x]) continue;
                if (sz[y] > sz[son[x]]) {
                    son[x] = y;
                }
            }
            if (son[x]) {
                self(son[x], p);
            }
            for (auto y: e[x]) {
                if (y == fa[x] || y == son[x]) continue;
                self(y, y);
            }
        }(v, v);

        auto lca = [&](int x, int y) {
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) {
                    swap(x, y);
                }
                x = fa[top[x]];
            }
            return (dep[x] < dep[y] ? x : y);
        };

        int gray = 0;
        for (int i = 1; i <= n; i++) {
            int j = k - i;
            if (j < 1 || j > n || i == j) {
                continue;
            }
            int z = lca(i, j);
            // cout<<"z="<<z<<" i="<<i<<" j="<<j<<endl;
            if (z == v) {
                gray = 1;
                break;
            }
        }

        if (gray) {
            cout << k << "\n";
            return;
        }
    }

    cout << n << "\n";
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
