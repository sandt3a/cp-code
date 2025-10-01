#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

struct Node {
	int l, r;
	mutable set<Node> chs;

	Node() {}
	Node(int l_, int r_): l(l_), r(r_) {
	}

	bool operator < (const Node &rhs) const {
		if (l != rhs.l)
			return l < rhs.l;
		return r < rhs.r;
	}

	bool contains(const Node &rhs) const {
		return l <= rhs.l && rhs.r <= r;
	}
};

void insert(int l, int r, set<Node> &ss, Node interval) {
	assert(Node(l, r).contains(interval));
	auto y = ss.lower_bound(interval);
	if (y == ss.end() || !y->contains(interval)) {
		ss.insert(interval);
	} else {
		insert(y->l, y->r, y->chs, interval);
	}
}

long long powermod(long long x, long long y) {
	long long res = 1;
	while (y) {
		if (y&1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}
long long inv(long long x) {
	return powermod(x, MOD - 2);
}

long long f[MAXN];

void prepare(int n) {
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
}

long long dfs(const Node &x) 
{
	if (x.chs.empty()) {
		return f[x.r - x.l + 1] - 1;
	}
	long long ans = 1;
	int ll = x.l;
	for (auto y: x.chs) {
		ans = ans * dfs(y) % MOD;
		ans = ans * f[y.l - ll] % MOD;
		ll = y.r;
	}
	ans = ans * f[x.r-ll] % MOD;
	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;

	Node rt = Node(1, n);
	long long ans = 1;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		insert(1, n, rt.chs, Node(l, r));
		if (l == 1 && r == n) {
			ans--;
		}
	}
	
	ans += dfs(rt);
	cout << ans % MOD << "\n";
}

int main()
{
	prepare(200000);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
