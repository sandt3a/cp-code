#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	int maxk = min(n, m);
	maxk = min(maxk, (n+m)/3);
	int nn = n - maxk;
	int mm = m - maxk;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> h(nn + mm);
	for (int i = 0; i < nn; i++) {
		h.push_back(a[n-i-1] - a[i]);
	}
	for (int i = 0; i < mm; i++) {
		h.push_back(b[m-i-1] - b[i]);
	}
	sort(h.begin(), h.end());
	reverse(h.begin(), h.end());

	vector<long long> ans(maxk + 1);
	priority_queue<int, vector<int>, greater<int>> pq;
	//priority_queue<int> pq;

	long long cur = 0;
	for (int i = 0; i < maxk; i++) {
		cur += h[i];
		ans[maxk] = cur;
		pq.push(h[i]);
	}

	int t = nn, r = mm;
	for (int i = maxk - 1; i >= 1; i--) {
		cur -= h[i];
		pq.pop();
		auto modify = [&](const vector<int> &a, int &t, int n) {
			while (t < n/2 && t < n-i) {
				int v = a[n-t-1] - a[t];
		//		cout<<"v="<<v<<endl;
		//		cout<<"pq.top()="<<pq.top()<<endl;
				if (v > pq.top()) {
					cur -= pq.top();
					pq.pop();
					pq.push(v);
					cur += v;
				}
				t++;
			}
		};
		modify(a, t, n);
		modify(b, r, m);
		ans[i] = cur;
	}
	
	cout << maxk << "\n";
	for (int i = 1; i <= maxk; i++) {
		cout << ans[i] << " \n"[i == maxk];
	}
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

