#include <bits/stdc++.h>
using namespace std;

template<class T>
void add_mod(T &x, const T &y, const T &mod) {
    x += y;
    if (x >= mod) {
        x %= mod;
    }
}

void solve()
{
    int n, mod;
    cin >> n >> mod;

    auto add = [&]<class T>(T &x, const T &y) {
        add_mod(x, y, mod);
    };

    std::vector dp(n + 1, std::vector<int> (n + 1, 0));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            add(dp[i + 1][j], dp[i][j]);

            int val = 1ll * dp[i][j] * (i-j+1) % mod * (n-i) % mod;
            add(dp[i + 1][j + 1], val);
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        add(ans, dp[n][i]);
    }
    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("d.in", "r", stdin);
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
