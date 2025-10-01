#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, l, r;
	cin >> n >> l >> r;
	l--;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.begin()+l);
	sort(a.begin()+l, a.begin()+r);
	sort(a.begin()+r, a.begin()+n);
	reverse(a.begin() + l, a.begin() + r);
	long long d = 0;
	long long sum = 0, sum_mid = 0;
	for (int i = 0; i < (r-l) && i < l; i++) {
		sum += a[i];
		sum_mid += a[i + l];
		d = max(d, sum_mid - sum);
	}
	sum = 0, sum_mid = 0;
	for (int i = r; i-(r-l) < r && i < n; i++) {
		sum += a[i];
		sum_mid += a[i - (r-l)];
		d = max(d, sum_mid - sum);
	}
	//cout<<"d="<<d<<endl;
	long long ans = accumulate(a.begin() + l, a.begin() + r, 0LL) - d;
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
