#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct Node {
    int l, r;
    mutable i64 v;

    bool operator<(const Node &rhs) const {
        return l < rhs.l;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<Node> pre, suf;
    pre.insert({0, n, 0LL});
    suf.insert({0, n, 0LL});

    vector<i64> b(n), c(n);
    i64 sum = 0;
    i64 sum_pre = 0;
    i64 sum_suf = 0;
    i64 maxa = 0;

    auto work = [&](set<Node> &ss, i64 &s, vector<i64> &b, int x, int delta) {
        b[x] += delta;
        maxa = max(maxa, b[x]);

        auto it = std::prev(ss.upper_bound({x, 0, 0}));
        auto [l, r, v] = *it;
        if (b[x] > v) {
            it = ss.erase(it);
            s -= i64(r - l) * v;
            if (l < x) {
                ss.insert({l, x, v});
                s += i64(x - l) * v;
            }

            int nr = r;
            while (it != ss.end()) {
                if (it->v <= b[x]) {
                    nr = it->r;
                    s -= i64(it->r - it->l) * it->v;
                    it = ss.erase(it);
                } else {
                    break;
                }
            }

            r = nr;
            ss.insert({x, r, b[x]});
            s += i64(r - x) * b[x];
        }
    };

    for (int i = 0; i < n; i++) {
        work(pre, sum_pre, b, i, a[i]);
        work(suf, sum_suf, c, n - 1 - i, a[i]);
        sum += a[i];
    }

    // for (auto [l,r,v]: pre) {
    //     cout<<"l="<<l<<" r="<<r<<" v="<<v<<endl;
    // }
    // for (auto [l,r,v]: suf) {
    //     cout<<"l="<<l<<" r="<<r<<" v="<<v<<endl;
    // }
    // cout << sum_pre + sum_suf - sum - maxa * n<<endl;

    int q;
    cin >> q;

    while (q--) {
        int x, v;
        cin >> x >> v;
        x--;
        work(pre, sum_pre, b, x, v);
        work(suf, sum_suf, c, n - 1 - x, v);
        sum += v;
        i64 ans = sum_pre + sum_suf - sum - maxa * n;
        cout << ans << "\n";
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
