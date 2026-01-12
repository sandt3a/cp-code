#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

constexpr int inf = 0x3f3f3f3f;

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
        n = (int)init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p].x = init_[l];
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
};

struct Info {
    int x = inf;

    friend Info operator+(const Info &a, const Info &b) {
        return {min(a.x, b.x)};
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree<Info> seg(a);
   // for (int i = 0; i < n; i++) {
   //     cout << seg.rangeQuery(i, i + 1).x<<endl;
   // }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            int p = x - 1;
            int v = y;
            seg.modify(p, Info{v});
        } else {
            x--;
            y--;
            int l = x;
            int r = y;
            while (l < r) {
                int m = (r + l) / 2;
                //cout<<"seg.rangeQuery(x, m + 1).x="<<seg.rangeQuery(x, m + 1).x<<"m="<<m<<endl;
                if (seg.rangeQuery(x, m + 1).x <= m - x) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            //cout << "l="<<x<<" m="<<l<<" val="<<seg.rangeQuery(x, l + 1).x<<endl;
            if (seg.rangeQuery(x, l + 1).x == l - x) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
