#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    i64 m;
    cin >> n >> m;

    if (m < n || m > 1ll * n * (n+1) / 2) {
        cout << -1 << "\n";
        return;
    }

    vector<i64> base(n + 1);
    for (int i = 1; i <= n; i++) {
        base[i] = base[i - 1] + i;
    }

    vector<int> vis(n + 1);
    vector<int> label(n + 1);

    auto work = [&](int n, i64 m) {
        int cur = 1, r = n;
        int rt = 0;

        while (m && n > 0) {
            int x = int(upper_bound(base.begin(), base.end(), m - n) - base.begin());
            if (!rt) rt = x;
            if (!vis[x]) {
                vis[x] = true;
                label[cur] = x;
            } else {
                while (vis[r]) {
                    r--;
                }
                label[cur] = r;
                vis[r] = true;
            }
            cur++;
            n--;
            m -= x;
        }
        assert(n == 0 && m == 0);
        return rt;
    };

    int rt = work(n, m);

    cout << rt << "\n";
    for (int i = 1; i + 1 <= n; i++) {
        cout << label[i] << " " << label[i + 1] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
