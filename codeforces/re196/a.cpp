#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int sgn(int x) {
    if (x == 0) return 0;
    return x < 0 ? -1 : 1;
}

void solve()
{
    int l, r;
    cin >> l >> r;

    int ans;
    if (sgn(l) == sgn(r)) {
        ans = r - l;
    } else {
        ans = max(0, abs(r + l) - 1);
    }
    cout << ans << "\n";
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
