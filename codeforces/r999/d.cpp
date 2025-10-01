#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve()
{
	int n, m;
	cin >> n >> m;
	multiset<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}
	multiset<int> b;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b.insert(x);
	}
	while (!b.empty() && b.size() <= a.size()) {
		int x = *b.rbegin();
		auto it = a.lower_bound(x);
		if (it != a.end() && *it == x) {
			a.erase(it);
			b.erase(b.find(x));
		} else {
			b.erase(b.find(x));
			b.insert(x/2);
			b.insert((x+1)/2);
//			cout<<"x="<<x<<endl;
		}
	}
//	cout<<b.size()<<"\n";
	if (!b.empty() || !a.empty()) {
		cout<<"No\n";
		return;
	}

	cout<<"Yes\n";
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
