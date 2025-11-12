#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<i64> v(n);
    vector<i64> l(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(v.begin(), v.end());
    sort(l.begin(), l.end(), greater<>());

    int q;
    cin >> q;

    vector<int> t(q), id(q);
    for (int i = 0; i < q; i++) {
        cin >> t[i];
        id[i] = i;
    }
    sort(id.begin(), id.end(), [&](int x, int y) {
        return t[x] < t[y];
    });

    i64 sv = accumulate(v.begin(), v.end(), 0LL);
    i64 sl = accumulate(l.begin(), l.end(), 0LL);

    int cur = 0;
    vector<i64> ans(q);
    for (int i = 0; i < n; i++) {
        while (cur < q) {
            int t0 = t[id[cur]];
            if (v[i] - l[i] * t0 < 0) {
                break;
            }
            ans[id[cur]] = max(0LL, sv - sl * t0);
            cur++;
        }
        sv -= v[i];
        sl -= l[i];
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q-1];
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
