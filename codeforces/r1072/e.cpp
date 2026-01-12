#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

i64 c2(i64 x) {
    return x * (x - 1) / 2;
}

struct DSU {
    std::vector<int> f, siz;
    i64 val;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        val = 0;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        val -= c2(siz[x]);
        val -= c2(siz[y]);
        siz[x] += siz[y];
        f[y] = x;
        val += c2(siz[x]);
        return true;
    }

    int size(int x) {
        return siz[find(x)];
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

    const int m = n - 1;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        d[i] = abs(a[i + 1] - a[i]);
    }

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return d[x] > d[y];
    });

    vector<i64> ans(m);
    DSU ss(n);

    int k = m - 1;
    for (auto id: ord) {
        int x = id;
        int y = id + 1;
        int w = d[id];

     //   cout<<"x="<<x<<" y="<<y<<" w="<<w<<endl;
        while (k >= 0 && w < k + 1) {
       //     cout<<"k="<<k<<endl;
            ans[k] = ss.val;
            k--;
        }

        ss.merge(x, y);
    }
    while (k >= 0) {
        ans[k] = ss.val;
        k--;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
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
