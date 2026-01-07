#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int l = k - 1;
    int r = n - k;
    if (l < r) {
        swap(l, r);
    }

    int ans;
    if (m <= 3*r - 1) {
        ans = 1 + (2*m + 2) / 3;
    } else {
        ans = 1 + 2 * r + min(l - r, (m - (3*r - 1))/2);
    }
    ans = min(ans, n);
    cout << ans << endl;
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
