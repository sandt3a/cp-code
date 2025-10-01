#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    using data = array<int, 3>;
    set<data> ss;

    for (int i = 0; i < n; ) {
        int j = i;
        int v = a[i];
        while (j < n && a[j] == v) {
            j++;
        }
        ss.insert({i, j, v});
        i = j;
    }

    auto get = [&](int l, int r) {
        i64 a = r - l;
        i64 b = l;
        i64 c = n - r;
        return b * c + a * (b + c) + a * (a + 1) / 2;
    };

    i64 ans = 0;
    for (auto [l, r, v]: ss) {
        ans += get(l, r);
    }

    // cout<<"ans="<< ans << endl;
    for (int _ = 0; _ < m; _++) {
        int i, x;
        cin >> i >> x;
        i--;

        auto it = std::prev(ss.upper_bound({i, n+1, 0}));
        auto [l, r, v] = *it;

        if (v == x) {
            cout << ans << endl;
            continue;
        }

        ans -= get(l, r);

        int nl = i;
        int nr = i + 1;

        if (l < i) {
            ans += get(l, i);
            ss.insert({l, i, v});
        } else if (it != ss.begin()) {
            auto pre = std::prev(it);
            auto [pl, pr, pv] = *pre;
            if (pv == x) {
                nl = pl;
                ans -= get(pl, pr);
                ss.erase(pre);
            }
        }
        if (i + 1 < r) {
            ans += get(i + 1, r);
            ss.insert({i + 1, r, v});
        } else {
            auto nxt = std::next(it);
            if (nxt != ss.end()) {
                auto [xl, xr, xv] = *nxt;
                if (xv == x) {
                    nr = xr;
                    ans -= get(xl, xr);
                    ss.erase(nxt);
                }
            }
        }
        ans += get(nl, nr);
        ss.erase(it);
        ss.insert({nl, nr, x});
        cout << ans << endl;
    }

    return 0;
}