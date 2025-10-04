#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, xk, yk, xd, yd;
    cin >> n >> xk >> yk >> xd >> yd;

    auto f = [&](int x, int y) {
        int d1 = abs(x - xk) + abs(y - yk);
        int d2 = max(abs(x - xd), abs(y - yd));
        return d2 > d1 ? d2 : 0;
    };

    int ans = max({f(0, 0), f(0, n), f(n, n), f(n, 0), 
        f(xk, 0), f(xk, n), f(0, yk), f(n, yk)});
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