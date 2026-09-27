#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int oo = 0x3f3f3f3f;

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

vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

vector<int> pws;
vector<int> prk;

void init()
{
    const int n = 400000;
    sieve(n);
    prk.assign(n + 1, 0);

    for (auto p: primes) {
        for (int x = p; ; x *= p) {
            pws.push_back(x);
            if (x > n / p) break;
        }
    }

    sort(pws.begin(), pws.end());
    for (int i = 0; i < (int)pws.size(); i++) {
        prk[pws[i]] = i;
    }
}

struct Info {
    int x = oo;
};

Info operator+(const Info &lhs, const Info &rhs) {
    return (Info){min(lhs.x, rhs.x)};
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = (int)(upper_bound(pws.begin(), pws.end(), n) - pws.begin() + 1);

    SegmentTree<Info> seg(m, {-1});
    vector<int> lst(m, -1);
    vector<bool> ok(m);

    for (int i = 0; i < n; i++) {
        vector<int> ids;

        int val = a[i];
        while (val > 1) {
            int p = minp[val];
            int pw = 1;
            while (val % p == 0) {
                val /= p;
                pw *= p;
                ids.push_back(prk[pw]);
            }
        }

        for (auto id: ids) {
            if (ok[id]) continue;
            if (i - lst[id] > 1 && seg.rangeQuery(0, id).x > lst[id]) {
                ok[id] = true;
            }
        }
        for (auto id: ids) {
            lst[id] = i;
            seg.modify(id, {i});
        }
    }

    for (int i = 0, mn = oo; i < m; i++) {
        //cout<<"i="<<i<<" lst[i]="<<lst[i]<<endl;
        if (!ok[i] && n - lst[i] > 1 && mn > lst[i]) {
            ok[i] = true;
        }
        mn = min(mn, lst[i]);
    }

    vector<int> ans;

    for (int i = 0; i < m; i++) {
        if (ok[i]) {
            ans.push_back(pws[i]);
        }
    }

    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " \n"[x == ans.back()];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
