#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

template<class T = i64, bool isMax = true>
struct LiChaoTree {
    struct Line {
        T k, b;

        T operator()(T x) const {
            return k * x + b;
        }
    };

    struct Node {
        Line ln{0, 0};
        int lc = -1, rc = -1;
        bool used = false;
    };

    static constexpr T INF = T(1) << (sizeof(T) * 8 - 2);

    T xl, xr;
    std::vector<Node> tr;

    LiChaoTree(T xl_, T xr_) : xl(xl_), xr(xr_) {
        tr.emplace_back();
    }

    bool better(const Line &a, const Line &b, T x) const {
        return isMax ? a(x) > b(x) : a(x) < b(x);
    }

    int newNode() {
        tr.emplace_back();
        return (int)tr.size() - 1;
    }

    void addLine(int p, T l, T r, Line ln) {
        if (!tr[p].used) {
            tr[p].used = true;
            tr[p].ln = ln;
            return;
        }
        T mid = l + (r - l) / 2;
        if (better(ln, tr[p].ln, mid)) {
            std::swap(ln, tr[p].ln);
        }
        if (l == r) {
            return;
        }
        if (better(ln, tr[p].ln, l)) {
            if (tr[p].lc == -1) {
                tr[p].lc = newNode();
            }
            addLine(tr[p].lc, l, mid, ln);
        } else if (better(ln, tr[p].ln, r)) {
            if (tr[p].rc == -1) {
                tr[p].rc = newNode();
            }
            addLine(tr[p].rc, mid + 1, r, ln);
        }
    }

    void addLine(T k, T b) {
        addLine(0, xl, xr, {k, b});
    }

    void addSegment(int p, T l, T r, T ql, T qr, Line ln) {
        if (qr < l || r < ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            addLine(p, l, r, ln);
            return;
        }
        T mid = l + (r - l) / 2;
        if (ql <= mid) {
            if (tr[p].lc == -1) {
                tr[p].lc = newNode();
            }
            addSegment(tr[p].lc, l, mid, ql, qr, ln);
        }
        if (qr > mid) {
            if (tr[p].rc == -1) {
                tr[p].rc = newNode();
            }
            addSegment(tr[p].rc, mid + 1, r, ql, qr, ln);
        }
    }

    void addSegment(T l, T r, T k, T b) {
        addSegment(0, xl, xr, l, r, {k, b});
    }

    T query(T x) const {
        T res = isMax ? -INF : INF;
        int p = 0;
        T l = xl, r = xr;
        while (p != -1) {
            if (tr[p].used) {
                T v = tr[p].ln(x);
                if (isMax ? v > res : v < res) {
                    res = v;
                }
            }
            if (l == r) {
                break;
            }
            T mid = l + (r - l) / 2;
            if (x <= mid) {
                p = tr[p].lc;
                r = mid;
            } else {
                p = tr[p].rc;
                l = mid + 1;
            }
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<i64> pre(n + 1);
    i64 base = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        base += a[i] * i64(i);
    }

    i64 ans = base;

    LiChaoTree<i64> seg(-1e6, 1e6);

    // j ...... i
    // ai -> j : ai * (j-i) + S(i-1) - S(j-1) // [j,i)

    for (int i = 1; i <= n; i++) {
        ans = max(ans, base - a[i] * i64(i) + pre[i - 1] + seg.query(a[i]));
        seg.addLine(i, -pre[i - 1]);
    }

    LiChaoTree<i64> seg2(-1e6, 1e6);

    // i ...... j
    // ai -> j : ai * (j-i) - (Sj - Si) // (i, j]
    for (int i = n; i >= 1; i--) {
        ans = max(ans, base - a[i] * i64(i) + pre[i] + seg2.query(a[i]));
        seg2.addLine(i, -pre[i]);
    }

    cout << ans << endl;
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
