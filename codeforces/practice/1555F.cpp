#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

const int N = 9e5 + 5;

struct LCT
{
    int n;
	int fa[N], c[N][2], rev[N];
    int val[N], typ[N];
    int sum[N], blk[N];

    int newnode(int value, int type) {
        int id = ++n;
        val[id] = value;
        typ[id] = type;
        return id;
    }

	void update(int o) {
		sum[o] = sum[c[o][0]] ^ sum[c[o][1]] ^ val[o];
		blk[o] = blk[c[o][0]] | blk[c[o][1]] | typ[o];
	}
	void pushdown(int o) {
		if(rev[o]) {
			rev[o] = 0;
			rev[c[o][0]] ^= 1;
			rev[c[o][1]] ^= 1;
			swap(c[o][0], c[o][1]);
		}
	}
	bool ch(int o) {
		return o == c[fa[o]][1];
	}
	bool isroot(int o) {
		return c[fa[o]][0] != o && c[fa[o]][1] != o;
	}
	void setc(int x, int y, bool d) {
		if(x) fa[x] = y;
		if(y) c[y][d] = x;
	}
	void rotate(int x) {
		if(isroot(x)) return;
		int p = fa[x], d = ch(x);
		if(isroot(p)) fa[x] = fa[p];
		else setc(x, fa[p], ch(p));
		setc(c[x][d^1], p, d);
		setc(p, x, d^1);
		update(p);
		update(x);
	}
	void splay(int x) {
		static int q[N], top;
		int y = q[top = 1] = x;
		while(!isroot(y)) q[++top] = y = fa[y];
		while(top) pushdown(q[top--]);
		while(!isroot(x)) {
			if(!isroot(fa[x]))
				rotate(ch(fa[x]) == ch(x) ? fa[x] : x);
			rotate(x);
		}
	}
	void access(int x) {
        int z = x;
		for(int y = 0; x; y = x, x = fa[x])
			splay(x), c[x][1] = y, update(x);
        splay(z);
	}
	void makeroot(int x) {
		access(x), rev[x] ^= 1;
	}
    int findroot(int x) {
        access(x);
        while (c[x][0]) { pushdown(x); x = c[x][0]; }
        splay(x);
        return x;
    }
	void link(int x, int y) {
		makeroot(x), fa[x] = y, splay(x);
	}
	void cut(int x, int y) {
		makeroot(x);
		access(y);
		c[y][0] = fa[x] = 0;
        update(y);
	}
    bool connect(int x, int y) {
        return findroot(x) == findroot(y);
    }
    vector<int> get_path(int x, int y) {
        static int stk[N];
        makeroot(x);
        access(y);

        vector<int> res;
        int top = 0, cur = y;
        while (cur || top) {
            while (cur) {
                pushdown(cur);
                stk[++top] = cur;
                cur = c[cur][0];
            }
            cur = stk[top--];
            res.push_back(cur);
            cur = c[cur][1];
        }
        return res;
    }
} lct;

void solve()
{
    int n, q;
    cin >> n >> q;

    lct.n = n;

    DSU dsu(n + 1);

    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;

        if (dsu.same(u, v)) {
            lct.makeroot(u);
            lct.access(v);
            if (lct.blk[v] || lct.sum[v] == x) {
                cout << "NO\n";
            } else {
                cout << "YES\n";

                auto nodes = lct.get_path(u, v);
                for (int i = 0; i + 1 < (int)nodes.size(); i++) {
                    lct.cut(nodes[i], nodes[i + 1]);
                }
                int s = lct.newnode(0, 1);
                for (auto p: nodes) {
                    if (p <= n) {
                        lct.link(s, p);
                    }
                }
            }
        } else {
            cout << "YES\n";
            int e = lct.newnode(x, 0);
            lct.link(u, e);
            lct.link(e, v);
            dsu.merge(u, v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
