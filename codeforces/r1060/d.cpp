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

    vector<int> fa(n), dep(n);
    vector<int> pend;

    std::function<void(int, int)> dfs = [&](int x, int p) {
        fa[x] = p;
        dep[x] = (p != -1 ? dep[p] + 1 : 0);
        for (auto y: e[x]) {
            if (y == p) continue;
            dfs(y, x);
        }
        if (x != n - 1) {
            pend.push_back(x);
        }
    };

    dfs(n - 1, -1);

    vector<array<int, 2>> ans;

    int cur = dep[0] & 1;
    for (auto x: pend) {
        ans.push_back({1, x});
        cur ^= 1;
        if (cur == (dep[x] & 1)) {
            ans.push_back({1, x});
            cur ^= 1;
        }
        ans.push_back({2, x});
    }

    cout << ans.size() << endl;
    for (auto [op, x]: ans) {
        if (op == 1) {
            cout << "1\n";
        } else {
            cout << op << " " << x + 1 << "\n";
        }
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
