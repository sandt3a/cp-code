#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int inf = 0x3f3f3f3f;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    Info query(int p) {
        return rangeQuery(1, 0, n, p, p + 1);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
    array<int, 2> val = {inf, -1};
};

Info operator+(const Info &a, const Info &b) {
    return {min(a.val, b.val)};
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<array<int, 2>> intvl(n);
    vector<vector<array<int, 3>>> upd(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) continue;
        int l = max(0, i - a[i] + 1);
        int r = min(n, i + a[i]);
        upd[i].push_back({l, i, i + 1});
        upd[l].push_back({l, r, i + 1});
        intvl[i] = {l, r};
    }

    vector<array<int, 2>> dp(n + 1, {inf, -1});
    dp[0] = {0, -1};

    SegmentTree<Info> seg(n + 1);
    seg.modify(0, {1, -1});
    for (int i = 0; i <= n; i++) {
        if (i) {
            auto [_, r] = intvl[i - 1];
            seg.modify(r, Info{dp[i][0] + 1, i} + seg.query(r));
        }
        for (auto [l, r, x]: upd[i]) {
            dp[x] = min(dp[x], seg.rangeQuery(l, r + 1).val);
        }
    }

    auto [val, lst] = seg.query(n).val;

    if (val == inf) {
        cout << -1 << "\n";
        return;
    }

    vector<int> ans;
    for (int cur = lst; cur != -1; cur = dp[cur][1]) {
        ans.push_back(cur);
    }

    sort(ans.begin(), ans.end(), [&](int x, int y) {
        return a[x - 1] < a[y - 1];
    });

    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " \n"[x == ans.back()];
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
