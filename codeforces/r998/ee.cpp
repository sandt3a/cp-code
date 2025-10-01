#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
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
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve()
{
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    std::vector<std::array<int, 2>> f(m1), g(m2);
    for (int i = 0; i < m1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        f[i] = {x, y};
    }
    DSU ss(n), gg(n);
    for (int i = 0; i < m2; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        g[i] = {x, y};
        ss.merge(x, y);
    }
    int ans = 0;
    for (int i = 0; i < m1; i++) {
        auto [x, y] = f[i];
        if (!ss.same(x, y)) {
            ans++;
        } else {
            gg.merge(x, y);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!gg.same(i, ss.find(i))) {
            gg.merge(i, ss.find(i));
            ans++;
        }
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

