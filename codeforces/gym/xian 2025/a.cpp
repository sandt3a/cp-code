#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int inf = 0x3f3f3f3f;

struct Monster {
    int a, b;

    bool operator<(const Monster &rhs) const {
        if (a != rhs.a) {
            return a > rhs.a;
        }
        return b < rhs.b;
    }
};

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    vector<std::multiset<int>> ss;

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
        ss.assign(n, {});
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

    void insert(int p, int v) {
        ss[p].insert(v);
        auto iv = Info::gen(ss[p], p);
        modify(p, iv);
    }

    void remove(int p, int v) {
        ss[p].erase(ss[p].find(v));
        auto iv = Info::gen(ss[p], p);
        modify(p, iv);
    }
};

struct Info {
    int mx = 0;
    pair<int, int> mn = {inf, -1};
    int cnt = 0;

    static Info gen(const multiset<int> &ss, int pos) {
        if (ss.empty()) {
            return Info();
        }
        return {*ss.rbegin(), make_pair(*ss.begin(), pos), (int)ss.size()};
    }
};

Info operator+(const Info &a, const Info &b) {
    return {std::max(a.mx, b.mx), std::min(a.mn, b.mn), a.cnt + b.cnt};
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> val;
    vector<Monster> mons(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mons[i] = {a, b};
        val.push_back(a);
        val.push_back(b);
    }

    vector<array<int, 3>> qry(q);
    for (int i = 0; i < q; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        x--;
        qry[i] = {x, a, b};
        val.push_back(a);
        val.push_back(b);
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    int tot = (int)val.size();
    auto get = [&](int x) -> int {
        return (int)(lower_bound(val.begin(), val.end(), x) - val.begin());
    };

    for (int i = 0; i < n; i++) {
        auto [a, b] = mons[i];
        mons[i] = {get(a), get(b)};
    }

    for (int i = 0; i < q; i++) {
        auto [x, a, b] = qry[i];
        qry[i] = {x, get(a), get(b)};
    }

    SegmentTree<Info> sa(tot), sb(tot);

    auto insert = [&](Monster m) {
        auto [a, b] = m;
        //cout<<"insert"<<" a="<<a<<" b="<<b<<endl;
        sa.insert(a, b);
        sb.insert(b, a);
    };
    auto remove = [&](Monster m) {
        auto [a, b] = m;
        //cout<<"remove"<<" a="<<a<<" b="<<b<<endl;
        sa.remove(a, b);
        sb.remove(b, a);
    };
    auto get_ans = [&]() -> int {
        //cout<<"get_ans"<<endl;
        int a = sa.findLast(0, tot, [&](const Info &x) { return x.cnt > 0; });
        int biga = a;
        int b = sa.rangeQuery(a, tot).mn.first;
        for (;;) {
            auto [nb, na] = sa.rangeQuery(b, tot).mn;
            if (nb == b) {
                break;
            }
            b = nb;
            a = na;
        }

        //cout<<"vala="<<val[a]<<" valb="<<val[b]<<endl;
        remove({a, b});

        bool ok = sb.rangeQuery(b, tot).mx >= b;
        int res = sb.rangeQuery(0, biga).cnt + ok;

        insert({a, b});

        //cout<<"res="<<res<<" ok="<<ok<<endl;

        return n - res;
    };

    for (int i = 0; i < n; i++) {
        insert(mons[i]);
    }

    cout << get_ans() << "\n";
    for (int _ = 0; _ < q; _++) {
        auto [x, a, b] = qry[_];
        remove(mons[x]);
        mons[x] = {a, b};
        insert(mons[x]);
        cout << get_ans() << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
