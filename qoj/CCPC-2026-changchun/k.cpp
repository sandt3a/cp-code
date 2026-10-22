#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using Data = array<int, 2>;

struct Fenwick {
    int n;
    vector<int> a;

    Fenwick(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        a.assign(n + 1, 0);
    }

    void add(int x, int v) {
        x += 1;
        for (; x <= n; x += x & -x) {
            a[x] += v;
        }
    }

    int sum(int x) {
        x += 1;
        int r = 0;
        for (; x; x -= x & -x) {
            r += a[x];
        }
        return r;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<Data> op(m);
    for (int i = 0; i < m; i++) {
        int o, x;
        cin >> o >> x;
        op[i] = {o, x};
    }

    vector<Data> querys(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        querys[i] = {l, r};
    }

    vector<int> ord(q);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return querys[x][1] < querys[y][1];
    });

    deque<array<int, 3>> dq;
    dq.push_back({1, n, -1});

    Fenwick fw(m);

    auto insert = [&](int type, int pos, int idx) {
        if (type == 0) {
            while (!dq.empty() && dq.front()[1] <= pos) {
                int c = dq.front()[2];
                if (c != -1) {
                    fw.add(c, -1);
                }
                dq.pop_front();
            }
            if (!dq.empty() && dq.front()[0] <= pos) {
                dq.front()[0] = pos + 1;
            }
            dq.push_front({1, pos, idx});
            fw.add(idx, 1);
        } else {
            while (!dq.empty() && dq.back()[0] >= pos) {
                int c = dq.back()[2];
                if (c != -1) {
                    fw.add(c, -1);
                }
                dq.pop_back();
            }
            if (!dq.empty() && dq.back()[1] >= pos) {
                dq.back()[1] = pos - 1;
            }
            dq.push_back({pos, n, idx});
            fw.add(idx, 1);
        }
    };

    vector<int> ans(m);

    for (int r = 0, cur = 0; r < m; r++) {
        auto [o, x] = op[r];
        insert(o, x, r);

        while (cur < q && querys[ord[cur]][1] <= r) {
            ans[ord[cur]] = fw.sum(querys[ord[cur]][0], m - 1);
            cur++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
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
