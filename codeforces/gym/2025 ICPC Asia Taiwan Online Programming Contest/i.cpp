#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const i64 inf = 9e18;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = (int)init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
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
    void init(std::vector<int> init_) {
        n = (int)init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = {init_[l], init_[l], 0, 0};
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
    i64 rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return 0;
        }
        if (l >= x && r <= y) {
            return info[p].v;
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    i64 rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }

    void range_add_vent(int p, int l, int r, int x, int y, int a) {
        if (l >= y || r <= x) {
            return;
        }
        if (r - l == 1 && info[p].m <= a) {
            info[p].vent();
            return;
        }
        if (l >= x && r <= y && info[p].m > a) {
            apply(p, {a, 1});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        range_add_vent(2 * p, l, m, x, y, a);
        range_add_vent(2 * p + 1, m, r, x, y, a);
        pull(p);
    }

    void range_add_vent(int l, int r, int a) {
        range_add_vent(1, 0, n, l, r, a);
    }
};

struct Tag {
    i64 sum = 0;
    i64 cnt = 0;
    void apply(const Tag &t) & {
        sum += t.sum;
        cnt += t.cnt;
    }
};

struct Info {
    // current pressure
    // min val need to vent
    // cnt of vent
    // cnt of one
    i64 p;
    i64 m;
    i64 v;
    i64 o;

    void apply(const Tag &t) & {
        m -= t.sum;
        v += t.cnt * o;
    }

    void vent() & {
        p /= 2;
        bool flag = 0;
        if (p == 1) {
            p = inf;
            flag = 1;
        }
        m = p;
        v += 1;
        o = flag;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {
        0,
        min(a.m, b.m),
        a.v + b.v,
        a.o + b.o
    };
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    LazySegmentTree<Info, Tag> seg(p);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l--;

        if (op == 1) {
            int k;
            cin >> k;
            seg.range_add_vent(l, r, k);
        } else { // op == 2
            i64 ans = seg.rangeQuery(l, r);
            cout << ans << "\n";
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
