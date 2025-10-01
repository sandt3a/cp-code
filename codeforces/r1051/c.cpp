#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--;
        v--;

        if (x > y) {
            e[u].push_back(v);
            deg[v]++;
        } else {
            e[v].push_back(u);
            deg[u]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans(n);
    int cur = n;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans[x] = cur--;

        for (auto y: e[x]) {
            if (--deg[y] == 0) {
                q.push(y);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
