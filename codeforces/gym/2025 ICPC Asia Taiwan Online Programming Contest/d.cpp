#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    string s;
    cin >> s;

    int n = (int)s.size();

    vector<vector<int>> dp(n, vector<int> (n));

    std::function<int(int, int)> dfs = [&](int l, int r) -> int {
        if (l == r) {
            return 0;
        }
        if (r - l == 1) {
            return s[l] != s[r];
        }

        int &res = dp[l][r];
        //cout<<"l="<<l<<" r="<<r<<" dp="<<res<<endl;
        if (res) return res;
        res = (r - l + 1) / 2;
        res = min(res, dfs(l + 1, r - 1) + (s[l] != s[r]));
        res = min(res, dfs(l, r - 1) + 1);
        res = min(res, dfs(l + 1, r) + 1);
        return res;
    };

    int ans = dfs(0, n - 1);

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
