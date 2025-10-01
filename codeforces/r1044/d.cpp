#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 inf = 1LL << 60;

void solve()
{
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<i64> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = min<i64>({i == 0 ? h[i] : inf, 
            i >= 1 ? (dp[i - 1] + h[i] - 1) : inf, 
            i >= 2 ? (dp[i - 2] + h[i - 1] + max(0, h[i] - i)) : inf
        });
        // cout<<"i="<<i<<" dp="<<dp[i]<<endl;
    }
    cout << dp[n - 1] << "\n";
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
