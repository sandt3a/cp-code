#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    i64 P, m;
    cin >> P >> m;

    if (P == 2) {
        cout << m / 2 + 1 << "\n";
    } else {
        i64 t = (m + (P - 1)) / P + 1;
        i64 ans = t + 1;

        for (i64 i = t; i >= 0 && i >= t - 3; i--) {
            if (((1 + i * P) xor (P - 1)) > m) {
                ans--;
            }
        }

        cout << ans << "\n";
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
