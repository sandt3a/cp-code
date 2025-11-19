#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    const int m = *max_element(cnt.begin(), cnt.end());

    vector<i64> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= cnt[i]; j--) {
            dp[j] = (dp[j] + cnt[i] * dp[j - cnt[i]]) % MOD;
        }
    }

    i64 ans = 0;
    for (int i = m; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
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
