#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int inf = 0x3f3f3f3f;

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
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    vector<int> u(m);
    vector<int> v(m);

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> a[i] >> b[i];
        u[i]--;
        v[i]--;

        e[u[i]].push_back(i);
    }

    vector w(n, vector<int>(1 << n));
    for (int i = 0; i < n; i++) {
        for (auto id: e[i]) {
            w[i][1 << v[id]] = min(a[id], b[id]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < (1 << n); s++) {
            if (s >> i & 1) {
                continue;
            }

            int j = s & -s;
            w[i][s] = w[i][j] + w[i][s ^ j];
        }
    }

    vector<int> dp(1 << n, inf);
    dp[0] = 0;
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                continue;
            }

           // cout<<"i="<<i<<" s="<<s<<" w="<<w[i][s]<<endl;
            relax(dp[s | 1 << i], dp[s] + w[i][s]);
        }
    }

    int ans = inf;
    for (int s = 0; s < (1 << n); s++) {
        int cs = 0;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                continue;
            }
            cs += c[i];
        }
        relax(ans, dp[s] + cs);
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
