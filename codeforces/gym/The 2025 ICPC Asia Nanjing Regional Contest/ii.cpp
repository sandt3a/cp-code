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

__attribute__((target("avx"), optimize("O3", "unroll-loops")))
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<array<int, 6>> val(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d, e, p;
        cin >> a >> b >> c >> d >> e >> p;
        val[i] = {a, b, c, d, e, p};
    }

    vector dp(m + 1, vector(2, vector<r64>(2)));
    for (int i = n - 1; i >= 0; i--) {
        auto [a, b, c, d, e, p0] = val[i];

        vector ndp(m + 1, vector(2, vector<r64>(2, -1e15)));
        for (int cost = min(b, d); cost <= m; cost++) {
            if (cost >= d) {
                if ((p0 == 0 || dp[cost - d][1][0] > -eps) && (p0 == 100 || dp[cost - d][0][1] > -eps)) {
                    tense(ndp[cost][0][0], (dp[cost - d][1][0] * p0 + dp[cost - d][0][1] * (100-p0)) / 100 + c);
                }
                if ((p0 == 0 || dp[cost - d][1][0] > -eps) && (p0 == 100 || dp[cost - d][1][1] > -eps)) {
                    tense(ndp[cost][1][0], (dp[cost - d][1][0] * p0 + dp[cost - d][1][1] * (100-p0)) / 100 + c);
                }
                if ((p0 == 0 || dp[cost - d][1][1] > -eps) && (p0 == 100 || dp[cost - d][0][1] > -eps)) {
                    tense(ndp[cost][0][1], (dp[cost - d][1][1] * p0 + dp[cost - d][0][1] * (100-p0)) / 100 + c);
                }
            }
            if (cost >= d + e) {
                if (dp[cost - d - e][0][0] > -eps) {
                    tense(ndp[cost][1][1], dp[cost - d - e][0][0] + c);
                }
            }
            if (cost >= b) {
                for (int u: {0, 1}) {
                    for (int v: {0, 1}) {
                        if ((p0 == 0 || dp[cost - b][1][v] > -eps) && (p0 == 100 || dp[cost - b][u][1] > -eps)) {
                            tense(ndp[cost][u][v], (dp[cost - b][1][v] * p0 + dp[cost - b][u][1] * (100-p0)) / 100 + a);
                        }
                    }
                }
            }
        }

        swap(dp, ndp);
    }

    r64 ans = -1;
    for (int i = 0; i <= m; i++) {
        tense(ans, dp[i][0][0]);
    }

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
