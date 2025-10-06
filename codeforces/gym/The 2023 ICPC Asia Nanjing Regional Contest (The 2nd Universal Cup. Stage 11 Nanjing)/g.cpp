#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, W, k;
    cin >> n >> W >> k;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        a[i] = {w, v};
    }
    sort(a.begin(), a.end());

    i64 cur = 0;
    vector<i64> suf(n + 1);
    priority_queue<int, vector<int>, greater<int>> ss;
    for (int i = n - 1; i >= 0; i--) {
        auto [w, v] = a[i];
        if ((int)ss.size() < k) {
            ss.push(v);
            cur += v;
        } else if (k && ss.top() < v) {
            cur -= ss.top();
            ss.pop();
            ss.push(v);
            cur += v;
        }
        suf[i] = cur;
    }

    i64 ans = 0;
    vector<i64> dp(W + 1);
    for (int i = 0; i < n; i++) {
        auto [w, v] = a[i];
        for (int j = W; j >= w; j--) {
            ans = max(ans, dp[j] + suf[i]);
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    for (int j = 0; j <= W; j++) {
        ans = max(ans, dp[j]);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
