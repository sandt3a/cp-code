#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, k;
    cin >> n >> k;

    int maxw = 0;
    vector<vector<array<int, 2>>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
        maxw = max(maxw, z);
    }

    auto check = [&](i64 M) -> bool {
        vector<i64> dp(n);
        vector<int> flag(n);

        std::function<void(int, int)> dfs = [&](int x, int p) {
            i64 mx = -(1LL << 60);
            i64 smx = -(1LL << 60);

            auto update = [&](i64 x) {
                if (x > mx) {
                    smx = mx;
                    mx = x;
                } else if (x > smx) {
                    smx = x;
                }
            };

            for (auto [y, w]: e[x]) {
                if (y == p) continue;
                dfs(y, x);
                if (dp[y] + w > M) {
                    flag[y] = 1;
                    dp[x] = max<i64>(dp[x], w);
                    update(w);
                } else {
                    dp[x] = max(dp[x], dp[y] + w);
                    update(dp[y] + w);
                }
            }

            if (mx + smx > M) {
                flag[x] = 1;
                dp[x] = 0;
            }
        };

        dfs(0, -1);

        return count(flag.begin(), flag.end(), 1) <= k;
    };

    i64 L = maxw, R = 1LL * maxw * n, ans = -1;
    while (L <= R) {
        i64 M = L + (R-L)/2;
        if (check(M)) {
            ans = M;
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    cout << ans << "\n";
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
