#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 x, y;
    cin >> x >> y;

    i64 n = max(x, y);
    i64 ans;
    if (n % 2 == 0) {
        if (x == n) {
            ans = n * n - y + 1;
        } else {
            ans = (n-1)*(n-1) + x;
        }
    } else {
        if (y == n) {
            ans = n * n - x + 1;
        } else {
            ans = (n - 1) * (n - 1) + y;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

