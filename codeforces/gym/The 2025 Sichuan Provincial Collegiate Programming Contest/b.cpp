#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;

    std::vector<vector<array<int, 3>>> e(n);
    int SUMA = 0;
    for (int i = 0; i < m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;

        e[u].push_back({v, a, b});
        SUMA += a;
    }

    vector dp(n, vector<int>(SUMA + 1, inf));
    
    dp[0][0] = 0;
    for (int i = 0; i < SUMA; i++) {
        for (int x = 0; x < n; x++) {
            for (auto [y, a, b]: e[x]) {
                if (i + a <= SUMA) {
                    dp[y][i + a] = min(dp[y][i + a], dp[x][i] + b);
                }
            }
        }
    }

    int ans = -1;
    for (int i = 0; i <= SUMA; i++) {
        if (dp[n - 1][i] < inf) {
            if (ans == -1 || i64(i) * dp[n - 1][i] < i64(ans) * dp[n - 1][ans]) {
                ans = i;
            }
        }
    }

    cout << ans << " " << dp[n - 1][ans] << "\n";
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
