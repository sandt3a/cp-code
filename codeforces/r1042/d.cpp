#include <bits/stdc++.h>
using namespace std;

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

    vector<int> is_leaf(n);

    int ans = n;
    int tot = 0;
    std::function<void(int, int)> dfs = [&](int x, int p) {
        int res = 0;
        if (e[x].size() == 1u) {
            is_leaf[x] = true;
            tot++;
        }
        for (auto y: e[x]) {
            if (y == p) continue;
            dfs(y, x);
        }
        for (auto y: e[x]) {
            res -= is_leaf[y];
        }
        res -= is_leaf[x];
        ans = min(ans, res);
    };

    dfs(0, -1);

    ans += tot;
    // cout<<"tot="<<tot<<endl;
    cout << ans << "\n";
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