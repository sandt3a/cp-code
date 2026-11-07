#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    i64 m;
    cin >> n >> m;

    vector<array<i64, 3>> a(n);
    for (int i = 0; i < n; i++) {
        int w, l, r;
        cin >> w >> l >> r;
        a[i] = {w, l, r};
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    i64 base = 0, rem = m;
    vector<i64> cur(n);

    vector<i64> val(n);
    vector<i64> imp(n);
    vector<i64> preval(n + 1);
    vector<i64> preimp(n + 1);
    for (int i = 0; i < n; i++) {
        auto [w, l, r] = a[i];
        if (rem >= l) {
            i64 todo = min(rem, l);
            rem -= todo;
            cur[i] = todo;
            base += w * todo;
        }

        imp[i] = r - l;
        val[i] = w * imp[i];
        preval[i + 1] = preval[i] + val[i];
        preimp[i + 1] = preimp[i] + imp[i];
    }

    i64 ans = base;
    for (int i = 0; i < n; i++) {
        auto [w, l, r] = a[i];

        ans = max(ans, base + w * rem);

        int pos = (int)(lower_bound(preimp.begin(), preimp.end(), rem + l) - preimp.begin() - 1);
        i64 lt = rem + l - preimp[pos];
        ans = max(ans, base - l * w + preval[pos] + (pos < n ? a[pos][0] * lt : 0LL));
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
