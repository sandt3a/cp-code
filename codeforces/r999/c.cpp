#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> dp(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i][0] = a[i] == 0;
			dp[i][1] = 1;
		} else {
			if (i>=2)
				dp[i][0] += dp[i-1][1] * (a[i]-a[i-2]==1);
			else // i==1
				dp[i][0] += dp[i-1][1] * (a[i] == 1);
			dp[i][0] += dp[i-1][0] * (a[i]-a[i-1] == 0);
			dp[i][1] = dp[i-1][0];
		}
		for (int j = 0; j < 2; j++)
			dp[i][j] %= MOD;
	}
	int ans = dp[n-1][0] + dp[n-1][1];
	cout << ans % MOD << "\n";
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
