#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    i64 n, m, K, L;
    cin >> n >> m >> K >> L;

    if (n < m || K + L > n) {
        puts("-1");
        return;
    }

    i64 l = 1, r = n / m, res = -1;
    while (l <= r) {
        i64 mid = (r - l) / 2 + l;
        if (mid * m - K >= L) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}