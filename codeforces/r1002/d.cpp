#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

template<class T>
bool relax(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

void solve()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--;
    s2--;
    vector<vector<int>> g1(n), g2(n);
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    vector<bool> ok(n);
    int m1;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g1[x].push_back(y);
        g1[y].push_back(x);
        cnt[x][y]++;
        cnt[y][x]++;
    }
    int m2;
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g2[x].push_back(y);
        g2[y].push_back(x);
        if (cnt[x][y]) {
            ok[x] = ok[y] = true;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, inf));
    vector<vector<bool>> inq(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    dp[s1][s2] = 0;
    q.push({s1, s2});
    inq[s1][s2] = true;

    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        inq[a][b] = false;
        for (auto x: g1[a]) {
            for (auto y: g2[b]) {
                if (relax(dp[x][y], dp[a][b] + abs(x-y))) {
                    if (!inq[x][y]) {
                        inq[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
    }

    int ans = inf;
    for (int x = 0; x < n; x++) {
        if (!ok[x]) continue;
        relax(ans, dp[x][x]);
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << "\n";
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
