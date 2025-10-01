#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<vector<int>> e(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string ss;
		cin >> ss;
		for (int j = 0; j < n; j++) {
			e[i][j] = ss[j] - '0';
		}
	}
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&](int i, int j) -> bool {
			if (i < j)
				return e[i][j];
			else
				return !e[i][j];
			});
	for (int i = 0; i < n; i++) {
		printf("%d%c", p[i] + 1, " \n"[i == n - 1]);
	}
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
