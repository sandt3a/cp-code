#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int inf = 1LL << 30;

template<class T>
bool relax(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i - 1]; // time from 0 to i by stair
    }

    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i] += b[i - 1]; // time from 0 to i by elevator 
    }

    const auto get = [](const vector<int> &v, int l, int r) {
        return v[r] - (l ? v[l - 1] : 0);
    };

    // dp[i] - the min time from 0 to i
    // dp[i] <- dp[j<i] + min(get(a, j, i), get(b, j, i) + c);
    // j ++, get(a, j, i) --
    // wait wait
    // dp[i] <- dp[j] + val and + c for every time?

    vector<array<int, 2>> dp(n + 1, {inf, inf}); // min time arrive i, 0 by stair (last step), 1 by elevtar and in it
    dp[0] = {0, c};
    for (int i = 1; i < n; i++) {
        relax(dp[i][0], dp[i - 1][0] + get(a, i, i));
        relax(dp[i][0], dp[i - 1][1] + get(a, i, i));
        relax(dp[i][1], dp[i - 1][0] + get(b, i, i) + c);
        relax(dp[i][1], dp[i - 1][1] + get(b, i, i));
    }
    // cout<<get(a, 1, 2)<<endl;

    for (int i = 0; i < n; i++) {
        // cout<<"0:"<<dp[i][0]<<" 1:"<<dp[i][1]<<endl;
        int ans = min(dp[i][0], dp[i][1]);
        cout << ans << " \n"[i == n - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();    
    }

    return 0;
}