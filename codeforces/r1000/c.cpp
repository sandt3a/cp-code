#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> e(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	sort(a.begin(), a.end(), [&](int x, int y) { return e[x].size() < e[y].size(); });
	reverse(a.begin(), a.end());

	int ans = 1;
	if (n >= 3 && e[a[0]].size() == e[a[1]].size() && e[a[1]].size() == e[a[2]].size()) {
		ans = 2 * (int)e[a[0]].size() - 1;
	} else {
		int x = a[0];
		ans += (int)e[x].size() - 1;
//	cout << ans << "!!!\n";
		for (auto y: e[x]) {
			auto ss=e[y].size();
			e[y].pop_back();
			auto tt=e[y].size();
			assert(ss-tt==1u);
		}
		e[x].clear();
		e[x].resize(0);
		sort(a.begin(), a.end(), [&](int x, int y) { return e[x].size() < e[y].size(); });
		reverse(a.begin(), a.end());
		ans += (int)e[a[0]].size() - 1;
//		cout << ans << "!!\n";
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
