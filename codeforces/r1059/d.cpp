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

    auto get = [&](int ct, int l, int r) {
        cout << ct << " " << l << " " << r << endl;
        i64 res;
        cin >> res;
        return res;
    };

    int L, R;
    int len = get(2, 1, n) - get(1, 1, n);
    for (int l = 1, r = n; l <= r; ) {
        int m = (l + r) >> 1;
        auto v1 = get(1, m, n);
        auto v2 = get(2, m, n);
        if (v1 == v2) {
            r = m - 1;
        } else {
            l = m + 1;
            R = m;
            L = R - len + 1;
        }
    }
    cout << "! " << L << " " << R << endl;
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
