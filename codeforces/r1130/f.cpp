#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> down(n);
    auto dfs = [&](this auto &&self, int x, int p) -> void {
        int deg = 0;
        for (auto y: e[x]) {
            if (y == p) continue;
            self(y, x);
            if (down[y] == 0) {
                down[x] = 1;
            }
            deg++;
        }
        if (deg % 2 == 0) {
            down[x] = 1;
        }
    };

    dfs(0, -1);

    vector<int> cnt0(n);
    auto reroot = [&](this auto &&self, int x, int p, int up) -> void {
        cnt0[x] = up;
        for (auto y: e[x]) {
            if (y == p) continue;
            cnt0[x] += down[y] == 0;
        }
        int deg = (int)e[x].size() - 1;
        for (auto y: e[x]) {
            if (y == p) continue;
            int cnt = cnt0[x] - (down[y] == 0);
            self(y, x, cnt == 0 && deg % 2 == 1);
        }
    };

    reroot(0, -1, 0);

    vector<int> ans;
    for (int x = 0; x < n; x++) {
        if (cnt0[x] == 0 && e[x].size() % 2 == 0) {
            ans.push_back(x);
        }
    }

    if (ans.empty()) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
        cout << ans.size() << "\n";
        for (auto x: ans) {
            cout << x + 1 << " \n"[x == ans.back()];
        }
    }
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
