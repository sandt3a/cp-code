// 一个显然的思路是按高度从小到大转移
// 问题在于高度相同的不能互相转移，需要处理
// 我最终选择了把高度相同的作为一层，分层转移之后再更新并查集

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> f;
    vector<int> mx;

    DSU(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        mx.assign(n, 0);
    }

    int get(int x) {
        if (f[x] == x) {
            return x;
        } else {
            return f[x] = get(f[x]);
        }
    }

    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) return false;

        f[x] = y;
        mx[y] = max(mx[x], mx[y]);
        return true;
    }

    int get_max(int x) {
        x = get(x);
        return mx[x];
    }

    void update(int x, int v) {
        x = get(x);
        mx[x] = max(mx[x], v);
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return h[x] < h[y];
    });

    vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        rnk[ord[i]] = i;
    }

    vector<int> dp(n);
    DSU dsu(n);

    vector<array<int, 2>> pend;

    for (int _ = 0; _ < n; _++) {
        int i = ord[_];
        int val = 0;
        if (i > 0 && h[i] > h[i - 1]) {
            //dsu.merge(i - 1, i);
            pend.push_back({i - 1, i});
            val = max(val, dsu.get_max(i - 1));
        }
        if (i + 1 < n && h[i] > h[i + 1]) {
            //dsu.merge(i, i + 1);
            pend.push_back({i + 1, i});
            val = max(val, dsu.get_max(i + 1));
        }
        dp[i] = val + 1;
        dsu.update(i, dp[i]);
        if (_ == n - 1 || h[ord[_ + 1]] != h[i]) {
            for (auto [x, y]: pend) {
                dsu.merge(x, y);
            }
            pend.clear();
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
    solve();
    return 0;
}
