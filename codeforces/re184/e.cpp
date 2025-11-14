#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<i64> x(n);
    vector<i64> y(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] <<= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        y[i] <<= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    const int S = 1 << 4;
    const i64 inf = 1LL << 60;
    vector<i64> dp(S, -inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<i64> ndp(S, -inf);
        for (int s = 0; s < S; s++) {
            if (dp[s] == -inf) continue;
            ndp[s] = max(ndp[s], dp[s] + c[i]);
            for (int t = 0; t < S; t++) {
                if (s & t) continue;
                i64 val = dp[s];
                if (t & 1) val -= x[i];
                if (t & 2) val += x[i];
                if (t & 4) val -= y[i];
                if (t & 8) val += y[i];
                ndp[s | t] = max(ndp[s | t], val);
            }
        }
        dp = ndp;
    }

    cout << dp[S - 1] << endl;
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
