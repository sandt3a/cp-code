#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const i64 inf = 1LL << 60;

template<class T>
bool relax(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

void solve()
{
    int n, m, H;
    cin >> n >> m >> H;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<vector<array<int, 2>>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        e[x].push_back({y, w});
        e[y].push_back({x, w});
    }

    vector<vector<i64>> dp(n, vector<i64>(H + 1, inf));
    vector<vector<bool>> inq(n, vector<bool>(H + 1));

    dp[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});
    inq[0][0] = true;

    while (!q.empty()) {
        auto [x, d] = q.front();
        q.pop();
        inq[x][d] = false;

        for (auto [y, w]: e[x]) {
            int nd = h[y] >= h[x] ? d + h[y] - h[x] : 0;
            if (nd <= H && relax(dp[y][nd], dp[x][d] + w)) {
                if (!inq[y][nd]) {
                    q.push({y, nd});
                    inq[y][nd] = true;
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        i64 ans = inf;
        for (int j = 0; j <= H; j++) {
            relax(ans, dp[i][j]);
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << " \n"[i == n - 1];
    }
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
