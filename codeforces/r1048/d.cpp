#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

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

const int inf = 0x3f3f3f3f;

struct Info {
    int mn = inf;
    int mx = -inf;
    bool mono = true;
    pair<int, int> pre = {-1, -1};
    pair<int, int> suf = {-1, -1};
    bool ok = true;
};

bool cmp(pair<int,int> x, pair<int,int> y) {
    if (x.first == -1 || y.first == -1) {
        return true;
    }
    return x < y;
}

Info operator+(const Info &a, const Info &b) {
    auto p = a.pre;
    auto s = b.suf;
    if (p.first == -1 && a.mx > b.mn) {
        p = {a.mx, b.mn};
    }
    if (s.first == -1 &&  a.mx > b.mn) {
        s = {a.mx, b.mn};
    }
    return {min(a.mn, b.mn), max(a.mx, b.mx),
        a.mono && b.mono && a.mx < b.mn,
        p,
        s,
        a.ok && b.ok && cmp(a.suf, b.pre)
    };
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree<Info> seg(n);

    for (int i = 0; i < n; i++) {
        auto tmp = a[i];

        int x = -1, y = -1;
        if (i > 0) {
            if (a[i - 1] > a[i]) {
                x = a[i - 1];
                y = a[i];
            }
        }
        auto z = make_pair(x, y);
        seg.modify(i, (Info){tmp, tmp, true, z, z, true});
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        auto tmp = a[l];

        int x = -1, y = -1;
        if (l > 0) {
            if (a[l - 1] > a[l]) {
                x = a[l - 1];
                y = a[l];
            }
        }
        auto z = make_pair(x, y);
        seg.modify(l, {tmp, tmp, true, make_pair(-1,-1), make_pair(-1,-1), true});
        auto res = seg.rangeQuery(l, r);
        // cout<<"l="<<l<<" r="<<r<<" mdc="<<res.maxdc<<endl;
        // auto mnid = res.mn.second;
        // auto mxid = res.mx.second;

        // bool ok = seg.rangeQuery(l, mnid).mono && seg.rangeQuery(mxid + 1, r).mono;

        bool ok = res.mono || res.ok;
        cout << (ok ? "YES\n" : "NO\n");

        seg.modify(l, {tmp, tmp, true, z, z, true});
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
