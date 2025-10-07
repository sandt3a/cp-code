#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
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

    vector<array<i64, 3>> dp(n);
    vector<i64> g(n);

    auto get = [&](const array<i64, 3> &z) {
        return max({z[0], z[1], z[2]});
    };

    std::function<void(int, int)> dfs = [&](int x, int p) {
        assert(dp[x][0] == 0);
        assert(dp[x][1] == 0);
        assert(dp[x][2] == 0);

        i64 sg = 0;
        for (auto y: e[x]) {
            if (y == p) continue;
            dfs(y, x);

            sg += g[y];
        }

        dp[x][0] = a[x] + sg;
        for (auto y: e[x]) {
            if (y == p) continue;
            dp[x][1] = max(dp[x][1], a[x] + sg - g[y] + get(dp[y]));
        }

        multiset<i64> ss;
        for (auto y: e[x]) {
            if (y == p) continue;
            ss.insert(g[y] - dp[y][0]);
        }

        for (auto y: e[x]) {
            if (y == p) continue;
            if (t[y] != 3) continue;
            ss.erase(ss.find(g[y] - dp[y][0]));
            dp[x][2] = max(dp[x][2], a[x] + sg - g[y] + get(dp[y]) - *ss.begin());
            ss.insert(g[y] - dp[y][0]);
        }

        g[x] = get(dp[x]) - a[x];

       // for (int i = 0; i < 3; i++) {
       //     cout<<"x="<<x+1<<" dp=["<<dp[x][0]<<","<<dp[x][1]<<","<<dp[x][2]<<"] g="<<g[x]<<endl;
       // }
    };

    dfs(0, -1);

    i64 ans = get(dp[0]);
    cout << ans << "\n";
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
