#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> to(n);
    vector<vector<int>> from(n);
    for (int i = 0; i < n; i++) {
        cin >> to[i];
        from[to[i]].push_back(i);
        to[i]--;
    }

    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        in[to[i]]++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            que.push(i);
        }
    }
    vector<int> vis(n);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 1;
        if (--in[to[x]] == 0) {
            que.push(to[x]);
        }
    }

    vector<int> dep(n, -1);
    vector<int> col(n, -1);
    auto dfs = [&](this auto&& self, int x, int d = 0, int c = 0) {
        dep[x] = d;
        col[x] = c;
        for (auto y: from[x]) {
            if (in[y]) continue;
            dfs(y, d + 1);
        }
    };

    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        dfs(i, 0, ++tot);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (col[b] == -1) {
            cout << dep[a] + 
        }
        if (col[a] == -1 || col[a] != col[b]) {
            cout << "-1\n";
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
