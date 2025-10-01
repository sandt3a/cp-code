#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template<class T>
struct Fenwick
{
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

struct Max {
    int x = 0;
    Max& operator+=(Max a) {
        x = max(x, a.x);
        return *this;
    }
};

void solve()
{
    int n;
    cin >> n;

    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            if (a[i].empty() || a[i].back() < x) {
                a[i].push_back(x);
            }
        }
    }

    std::vector<int> val;
    for (int i = 0; i < n; i++) {
        for (auto x: a[i]) {
            val.push_back(x);
        }
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 0; i < n; i++) {
        for (auto &x: a[i]) {
            x = static_cast<int>(lower_bound(val.begin(), val.end(), x) - val.begin());
        }
    }

    sort(a.begin(), a.end(), [&](auto &x, auto &y) { return x.back() < y.back(); });

    Fenwick<Max> T(static_cast<int>(val.size()));

    int ans = 0;
    for (auto &vec: a) {
        int k = static_cast<int>(vec.size());
        int res = 0;
        for (int i = 0; i < k; i++) {
            res = max(res, k - i + T.sum(vec[i]).x);
        }
        T.add(vec.back(), {res});
        ans = max(ans, res);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
