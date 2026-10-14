#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 125000 + 5;

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> c(n);
    vector<int> a(m), b(m);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    if (c[0] >= a[0]) {
        for (int i = 0; i < s; i++) {
            cout << "NO\n";
        }
        return;
    }

    const int V = max({a.back(), s});

    bitset<N> bs;
    bs.set(0);
    for (int i = 0; i < n; i++) {
        bs.set(c[i]);
    }
    for (int i = 1; i <= V; i++) {
        if (bs[i]) {
            bs |= bs << i;
        }
    }

    bitset<N> ok, dp, aux;
    ok.set(0);
    dp.set(0);

    int dora = s + 1;
    bool flag = false;

    int g = b.back();
    for (int i = 0; i < n; i++) {
        g = std::gcd(g, c[i]);
    }

    for (int h = 1, i = -1; h <= V; h++) {
        while (i + 1 < m && a[i + 1] <= h) {
            i++;
        }

        if (bs[h]) {
            int v = i >= 0 ? h - b[i] : h;
            g = std::gcd(g, abs(v));
            if (v < 0) {
                if (!flag) {
                    dora = h;
                    flag = true;
                }
            } else if (v > 0) {
                aux.set(v);
            }
        }

        if (!flag) {
            dp <<= 1;
            ok[h] = (dp & aux).any();
            dp[0] = ok[h];
        }
    }

    for (int i = 1; i <= s; i++) {
        cout << ((i < dora ? (ok[i]) : (i % g == 0)) ? "YES\n" : "NO\n");
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
