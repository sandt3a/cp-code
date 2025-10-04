#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

constexpr int L = 18;

void solve()
{
    int n, z;
    cin >> n >> z;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dep(n + 1);
    vector<array<int, L>> f(n + 1);
    for (int i = 0, j = i; i < n; i++) {
        while (j < n && a[j] - a[i] <= z) {
            j++;
        }

        f[i][0] = j;
    }
    fill(f[n].begin(), f[n].end(), n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j + 1 < L; j++) {
            f[i][j + 1] = f[f[i][j]][j];
        }
        dep[i] = dep[f[i][0]] + 1;
    }

    auto lca = [&](int x, int y) -> int {
        if (dep[x] > dep[y]) {
            swap(x, y);
        }
        int d = dep[y] - dep[x];
        for (int i = L - 1; i >= 0; i--) {
            if (d >> i & 1) {
                y = f[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = L - 1; i >= 0; i--) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    };

    vector<array<int, L>> g(n + 1);
    vector<array<int, L>> h(n + 1);

    for (int i = 0; i < n; i++) {
        int z = lca(i, i + 1);
        g[i][0] = z;
        h[i][0] = dep[i] + dep[i + 1] - 2 * dep[z];
    }

    fill(g[n].begin(), g[n].end(), n);
    fill(h[n].begin(), h[n].end(), 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j + 1 < L; j++) {
            g[i][j + 1] = g[g[i][j]][j];
            h[i][j + 1] = h[i][j] + h[g[i][j]][j];
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if (r - l <= 2) {
            cout << r - l << "\n";
            continue;
        }

        int ans = 0;
        int x = l;
        for (int i = L - 1; i >= 0; i--) {
            if (g[x][i] < r) {
                ans += h[x][i];
                x = g[x][i];
            }
        }
  
        auto jmp = [&](int x, int r) {
            int res = 0;
            for (int i = L - 1; i >= 0; i--) {
                if (f[x][i] < r) {
                    res += 1 << i;
                    x = f[x][i];
                }
            }
            return res + 1;
        };

        if (x < r) {
            ans += jmp(x, r);
        }
        if (x + 1 < r) {
            ans += jmp(x + 1, r);
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}