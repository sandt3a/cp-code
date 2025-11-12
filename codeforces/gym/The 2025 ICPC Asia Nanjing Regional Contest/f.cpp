#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

struct DSU {
    int n;
    vector<int> f;

    DSU() {}
    DSU(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        f.assign(n, 0);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        if (f[x] == x) {
            return f[x];
        }
        return f[x] = find(f[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        f[x] = y;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

const int L = 12;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<DSU> dsu(1 << L, DSU(n));

    i64 ans = 0;
    while (q--) {
        char op;
        int u, v;
        cin >> op >> u >> v;
        u--;
        v--;

        if (op == '+') {
            int w;
            cin >> w;

            std::function<void(int)> add = [&](int val) {
                if (!dsu[val].merge(u, v)) {
                    return;
                }

                if (val == 0) return;
                for (int i = 0; i < L; i++) {
                    if (val >> i & 1) {
                        add(val ^ (1 << i));
                    }
                }
            };

            add(w);
        } else {
            if (!dsu[0].same(u, v)) {
                ans--;
                continue;
            }
            int cur = 0;
            for (int i = L - 1; i >= 0; i--) {
                if (dsu[cur | 1 << i].same(u, v)) {
                    cur |= 1 << i;
                }
            }
            ans += cur;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
