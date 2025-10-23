#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int inf = 0x3f3f3f3f;
const int L = 20;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> ord;
    vector<int> dep(n) ;
    vector<array<int, L>> f(n);
    vector<array<i64, L>> g(n);
    std::function<void(int, int)> dfs = [&](int x, int p) {
        ord.push_back(x);
        f[x][0] = p;
        dep[x] = p >= 0 ? dep[p] + 1 : 0;
        pair<int, int> mn = {inf, inf};
        for (auto y: e[x]) {
            if (y == p) continue;
            dfs(y, x);

            mn = min({mn, make_pair(c[y], mn.first), make_pair(mn.first, c[y])});
        }
        c[x] = min(c[x], mn.first + mn.second);
        for (auto y: e[x]) {
            if (y == p) continue;
            if (c[y] == mn.first) {
                g[y][0] = mn.second;
            } else {
                g[y][0] = mn.first;
            }
        }
    };

    dfs(0, -1);

    for (auto x: ord) {
        for (int i = 0; i + 1 < L; i++) {
            if (f[x][i] == -1) break;
            f[x][i + 1] = f[f[x][i]][i];
            g[x][i + 1] = g[x][i] + g[f[x][i]][i];
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (x == y) {
            cout << "0\n";
            continue;
        }
        if (dep[x] <= dep[y]) {
            cout << "-1\n";
            continue;
        }

        i64 ans = 0;

        for (int d = dep[x] - dep[y], i = 0; i < L; i++) {
            if (d >> i & 1) {
                ans += g[x][i];
                x = f[x][i];
            }
        }
        if (x != y) {
            ans = -1;
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
