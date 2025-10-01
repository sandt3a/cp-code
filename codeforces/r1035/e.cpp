#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 inf = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int n;
    cin >> n;

    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n - 1; i++) {
        c[i] |= a[i];
        c[i + 1] |= a[i];
    }

    const int k = 31;

    map<int, i64> dp;

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        map<int, i64> ndp;

        for (int j = 0; j <= k; j++) {
            if (c[i] >> j & 1) continue;
            int t = (b[i] >> j) << j;
            int y = j == k ? c[i] : c[i] ^ 1 << j;
            y |= t;
            if (y < b[i]) continue;
            ndp[y] = inf;

            for (auto [x, v]: dp) {
                if (v == inf) continue;
                if (i == 0 || (x & y) == a[i - 1]) {
                    ndp[y] = min(ndp[y], v + y - b[i]);
                }
            }
        }

        dp = ndp;

        // cout<<"-----\n";
        // for (auto [x, v]: dp) {
        //     if (v == inf) continue;
        //     cout << "x="<<x << "v=" << v << endl;
        // }
    }

    i64 ans = inf;
    for (auto [x, v]: dp) {
        ans = min(ans, v);
    }

    if (ans == inf) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("e.in", "r", stdin);
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
