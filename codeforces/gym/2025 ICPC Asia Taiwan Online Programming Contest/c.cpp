#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edge(m);
    for (int i = 0; i < m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        x--;
        y--;

        edge[i] = {x, y, v};
    }

    vector<i64> dp(n);
    for (auto [x, y, v]: edge) {
        i64 nx = dp[y] + v;
        i64 ny = dp[x] + v;
        dp[x] = nx;
        dp[y] = ny;
    }

    i64 ans = *max_element(dp.begin(), dp.end());
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
