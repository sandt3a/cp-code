#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;
using r128 = __float128;

const r64 eps = 1e-6;

template<class T, class U>
bool tense(T &x, const U& y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);
    vector<int> e(n);
    vector<r64> p(n);
    for (int i = 0; i < n; i++) {
        int p0;
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> p0;
        p[i] = r64(p0) / 100;
    }

    vector dp(n, vector<array<array<r64, 2>, 2>>(m + 1));
    vector vis(n, vector<array<array<bool, 2>, 2>>(m + 1));
    auto dfs = [&](auto &&self, int i, int cost, int u, int v) -> r64 {
        if (i == n) {
            return 0;
        }

        r64 &res = dp[i][cost][u][v];

        if (vis[i][cost][u][v]) {
            return res;
        }
        vis[i][cost][u][v] = true;

        res = -1e15;
        if (cost >= b[i]) {
            tense(res, self(self, i + 1, cost - b[i], 1, v) * p[i] + self(self, i + 1, cost - b[i], u, 1) * (1 - p[i]) + a[i]);
        }
        if ((!u || !v) && cost >= d[i]) {
            tense(res, self(self, i + 1, cost - d[i], 1, v) * p[i] + self(self, i + 1, cost - d[i], u, 1) * (1 - p[i]) + c[i]);
        }
        if (u && v && cost >= d[i] + e[i]) {
            tense(res, self(self, i + 1, cost - d[i] - e[i], 0, 0) + c[i]);
        }
        if (res < 0) {
            res = -1e15;
        }
        return res;
    };

    r64 ans = dfs(dfs, 0, m, 0, 0);

    if (ans < 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
