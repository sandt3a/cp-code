#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vector<int> f(1<<m, (1<<30)-1);
	for (int s = 0; s < (1<<m); s++) {
		for (int k = 0; k < m; k++) {
			if ((s>>k)&1) {
				f[s] &= b[k];
			}
		}
	}
	vector<int> h(n * m);
	for (int i = 0; i < n; i++) {
		vector<int> dp(m + 1, 0);
		for (int s = 0; s < (1<<m); s++) {
			int t = __builtin_popcount(s);
			dp[t] = max(dp[t], (a[i] - (a[i] & f[s])));
		}
		assert(dp[0] == 0);
		for (int j = 0; j < m; j++) {
			h.push_back(dp[j + 1] - dp[j]);
			//cout<<dp[j]<<" \n"[j==m-1];
		}
	}
	sort(h.begin(), h.end());
	reverse(h.begin(), h.end());
	long long ans = accumulate(a.begin(), a.end(), 0LL);
	for (int i = 0; i < k && i < (int)h.size(); i++) {
		ans -= h[i];
	}
	cout << ans << "\n";
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
