#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 inf = 1LL << 60;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto get = [&](vector<int> vec) {
        sort(vec.begin(), vec.end());
        int med = vec[vec.size() / 2];
        i64 res = 0;
        for (auto x: vec) {
            res += abs(x - med);
        }
        return res;
    };

    i64 ans = inf;
    for (int _ = 0; _ < 3; _++) {
        vector<i64> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - 3); j < i - 1; j++) {
                dp[i] = min(dp[i], dp[j] + get(vector(a.begin() + j, a.begin() + i)));
            }
        }
        ans = min(ans, dp[n]);
        rotate(a.begin(), a.begin() + 1, a.end());
    }

    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
