#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int eq = -1;
	for (int i = 0; i+1 < n; i++) {
		if (a[i] == a[i+1]) {
			eq = i;
		}
	}
	if (eq == -1) {
		cout<<-1<<"\n";
		return;
	}
	vector<int> b;
	for (int i = 0; i < n; i++) {
		if (i == eq || i == eq + 1) {
			continue;
		}
		b.push_back(a[i]);
	}
	for (int i = 0; i+1 < (int)b.size(); i++) {
		if (b[i+1]-b[i] < 2 * a[eq]) {
			cout<<a[eq]<<" "<<a[eq]<<" "<<b[i]<<" "<<b[i+1]<<"\n";
			return;
		}
	}
	cout<<"-1\n";
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
