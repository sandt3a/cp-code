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
    int find(int p, int l, int r, int x, int y, F &&pred, int pre) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p], pre)) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        if (pred(info[2 * p], pre)) {
            return find(2 * p, l, m, x, y, pred, pre);
        } else {
            return find(2 * p + 1, m, r, x, y, pred, pre + info[2*p].x);
        }
    }
    template<class F>
    int find(int l, int r, F &&pred) {
        return find(1, 0, n, l, r, pred, 0);
    }
};

struct Info {
    int x;
    int pm;

    Info() { x = 0; pm = 0; }
    Info(int v) { x = pm = v; }
    Info(int x_, int pm_) { x = x_, pm = pm_; }
    

    friend Info operator+(const Info &a, const Info &b) {
        return (Info){a.x + b.x, min(a.pm, a.x + b.pm)};
    }
};

void solve()
{
    int A, D;
    cin >> A >> D;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    const int S = 2000000 + 5;

    vector<int> s(n);
    vector<int> cnt(S, -1);
    for (int i = 0; i < n; i++) {
        s[i] = max(a[i] - A, 0) + max(d[i] - D, 0);
        cnt[s[i]]++;
    }

    SegmentTree<Info> seg(S);
    for (int i = 0; i < S; i++) {
        seg.modify(i, Info(cnt[i]));
    }

    int q;
    cin >> q;
    while (q--) {
        int x, na, nd;
        cin >> x >> na >> nd;
        x--;
        a[x] = na;
        d[x] = nd;

        int o = s[x];

        cnt[s[x]]--;
        seg.modify(s[x], Info(cnt[s[x]]));
        s[x] = max(a[x] - A, 0) + max(d[x] - D, 0);
        cnt[s[x]]++;
        seg.modify(s[x], Info(cnt[s[x]]));

        // cout<<"x="<<x<<" os="<<o<<" s[x]="<<s[x]<<" cnt="<<cnt[s[x]]<<endl;

        int pos = seg.find(0, S, [&](Info a, int pre) {
            return pre + a.pm < 0;
        });
        int ans = seg.rangeQuery(0, pos).x + pos;
        cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
