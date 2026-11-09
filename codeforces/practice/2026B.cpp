#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto calc = [&](vector<i64>& vec) -> i64 {
        int m = (int)vec.size() / 2;
        i64 res = 1;
        for (int i = 0; i < m; i++) {
            res = max(res, vec[2 * i + 1] - vec[2 * i]);
        }
        return res;
    };

    i64 ans = numeric_limits<i64>::max();
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            auto b = a;
            b.erase(b.begin() + i);
            ans = min(ans, calc(b));
        }
    } else {
        ans = min(ans, calc(a));
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
