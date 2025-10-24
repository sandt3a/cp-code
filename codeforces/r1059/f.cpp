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

    vector<array<int, 2>> intvl(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        intvl[i] = {l, r};
    }

    vector<int> ok(n);
    vector<array<int, 2>> e;
    for (auto [l, r]: intvl) {
        e.push_back({l, +1});
        e.push_back({r, -1});
        ok[l] |= 1;
        ok[r - 1] |= 2;
    }
    sort(e.begin(), e.end(), greater<>());
    int mxi = 0;
    vector<int> val(n + 1);
    for (int i = 0, cur = 0; i <= n; i++) {
        while (!e.empty() && e.back()[0] == i) {
            cur += e.back()[1];
            e.pop_back();
        }
        val[i] = cur;
        if (val[i] > val[mxi]) {
            mxi = i;
        }
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    if (val[mxi] == m) {
        swap(ans[0], ans[mxi]);
    } else if (*min_element(ok.begin(), ok.end()) == 3) {
        swap(ans[2], ans[1]);
    } else {
        for (int i = 0; i < n; i++) {
            if (ok[i] < 3) {
                if (i > 0 && ok[i] % 2 == 0) {
                    swap(ans[0], ans[i]);
                    swap(ans[i != 1], ans[i - 1]);
                    break;
                }
                if (i < n && ok[i] == 1) {
                    swap(ans[0], ans[i]);
                    swap(ans[i != 1], ans[i + 1]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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
