#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

constexpr int MOD = 998244353;

vector<vector<int>> ds;

void init(int n = 3000)
{
    ds.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            ds[j].push_back(i);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] > 1) {
        cout << "0\n";
        return;
    }

    vector<int> dp(m + 1);
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        vector<int> ndp(m + 1);
        for (int x = 1; x <= m; x++) {
            for (auto d: ds[x]) {
                if (x + d <= m) {
                    ndp[x + d] = (ndp[x + d] + dp[x]) % MOD;
                }
            }
        }
        if (a[i] == 0) {
            dp = ndp;
        } else {
            dp.assign(m + 1, 0);
            dp[a[i]] = ndp[a[i]];
        }
    }

    int ans = 0;
    if (a.back() == 0) {
        for (int x = 1; x <= m; x++) {
            ans = (ans + dp[x]) % MOD;
        }
    } else {
        ans = dp[a.back()];
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
