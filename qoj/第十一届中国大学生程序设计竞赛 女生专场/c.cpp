#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    i64 T;
    cin >> n >> T;

    vector<array<i64, 2>> a(n);
    for (int i = 0; i < n; i++) {
        i64 t, k;
        cin >> t >> k;
        a[i] = {t, k};
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        auto &[t, k] = a[i];
        if (ans + t <= T || ans + t <= k + T) {
            ans += t;
        } else {
            if (ans <= T) {
                auto d = min(T - ans, t);
                t -= d;
                ans += d;
            }
            if (ans <= k + T) {
                auto d = min(k + T - ans, t);
                t -= d;
                ans += d;
            }
            if (i && a[i - 1][0]) {
                ans++;
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
    while (t--) {
        solve();
    }

    return 0;
}
