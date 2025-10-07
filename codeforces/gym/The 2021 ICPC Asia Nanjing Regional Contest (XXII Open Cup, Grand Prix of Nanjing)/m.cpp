#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

int sgn(i64 x) {
    if (x == 0) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        if (n == 1) {
            cout << a[0] << endl;
        } else {
            cout << max(a[0] - a[1], a[1] - a[0]) << endl;
        }
        return;
    }

    sort(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            ans -= a[i];
        } else {
            ans += a[i];
        }
    }

    if (sgn(a[0]) * sgn(a.back()) == 1) {
        ans = max(ans - 2 * abs(a[0]), ans - 2 * abs(a.back()));
    }

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
