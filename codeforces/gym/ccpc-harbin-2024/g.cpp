#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(k);
    vector<int> busy(n);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
        busy[a[i]] = 1;
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> vis(n);
    vector<int> fa(n, -1);
    vector<int> ord;
    auto dfs = [&](this auto &&self, int x) {
        vis[x] = 1;
        ord.push_back(x);
        if (busy[x]) return;
        for (auto y: e[x]) {
            if (vis[y]) continue;
            fa[y] = x;
            self(y);
        }
    };

    int rt = -1;
    for (int i = 0; i < n; i++) {
        if (!busy[i]) {
            rt = i;
            break;
        }
    }
    if (rt == -1) {
        cout << "No\n";
        return;
    }
    dfs(rt);

    if (ranges::count(vis, 0)) {
        cout << "No\n";
        return;
    }

    vector<vector<int>> son(n);
    for (int x = 0; x < n; x++) {
        if (fa[x] != -1) {
            son[fa[x]].push_back(x);
        }
    }

    int step = n;
    for (int x = 0; x < n; x++) {
        if (son[x].empty()) {
            step--;
        }
    }
    cout << "Yes\n";
    cout << step << "\n";
    for (int x: ord) {
        if (son[x].empty()) continue;
        cout << x + 1 << " " << son[x].size();
        for (auto y: son[x]) {
            cout << " " << y + 1;
        }
        cout << "\n";
    }
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
