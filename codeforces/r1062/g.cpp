#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    auto val = a;
    val.push_back(inf);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 0; i < n; i++) {
        a[i] = (int)(lower_bound(val.begin(), val.end(), a[i]) - val.begin());
    }

    const int m = (int)val.size();
    vector<i64> dp(m, 1LL << 60);
    dp[m - 1] = 0;

    for (int i = n - 1; i >= 0; i--) {
        vector<i64> ndp = dp;
        for (auto &x: ndp) {
            x += c[i];
        }

        for (int j = a[i]; j < m; j++) {
            ndp[a[i]] = min(ndp[a[i]], dp[j]);
        }

        dp = ndp;
    }

    cout << *min_element(dp.begin(), dp.end()) << "\n";
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
