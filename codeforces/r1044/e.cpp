#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<pair<int, int>> ans;

    vector<int> cnt(n);
    std::function<void(int, int)> dfs = [&](int x, int p) {
        cnt[x] = 1;
        for (auto y: e[x]) {
            if (y == p) continue;
            dfs(y, x);
            cnt[x] += cnt[y];
        }

        if (cnt[x] >= 4) {
            cnt[x] = 0;
            ans.push_back({2, x});
        }
        // cout<<"x="<<x<<" cnt="<<cnt[x]<<endl;
    };

    dfs(0, -1);

    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) continue;
        for (auto j: e[i]) {
            if (cnt[j] == 0) continue;
            deg[i]++;
            // deg[j]++;
        }
    }

    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i] || deg[i] >= 2) {
            continue;
        }

        std::function<void(int, int)> color = [&](int x, int p) {
            vis[x] = true;
            ans.push_back({1, x});
            for (auto y: e[x]) {
                if (cnt[x] == 0 || cnt[y] == 0 || vis[y]) {
                    continue;
                }
                color(y, x);
            }
        };

        color(i, -1);
    }

    cout << ans.size() << "\n";
    for (auto [op, x]: ans) {
        cout << op << " " << x + 1 << "\n";
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
