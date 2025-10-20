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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        auto calc = [&](int x) -> i64 {
            int l = (int)min<i64>(i, i64(x) * k);
            int r = min(n, i + x + 1);
           // cout<<"l="<<l<<" r="<<r<<" x="<<x<<endl;
            return pre[n] - pre[r] + pre[i] - pre[l] + i64(l + r - i) * a[i];
        };

        int l = 0, r = min(i, n - i - 1);
        while (l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = min(r, m1 + 1);
            i64 x = calc(m1);
            i64 y = calc(m2);
            if (x < y) {
                l = m1 + 1;
                ans = max(ans, y);
            } else {
                r = m2 - 1;
                ans = max(ans, x);
            }
        }
    }
    cout << ans << "\n";
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
