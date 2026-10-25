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
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<int> ord;
    vector<int> deg(n);
    vector<int> del(n);

    queue<int> q;

    for (int i = 0; i < n; i++) {
        deg[i] = (int)e[i].size();
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        del[x] = 1;
        ord.push_back(x);
        for (auto y: e[x]) {
            if (del[y]) continue;
            deg[y]--;
            if (deg[y] == 1) {
                q.push(y);
            }
        }
    }

    vector<int> ans(n + 2, -1);
    auto calc = [&](int k) -> int {
        if (ans[k] != -1) {
            return ans[k];
        }

        int res = 0;
        vector<int> mx(n);
        vector<int> mx2(n);

        for (auto x: ord) {
            int dp = mx[x] + 1;
            if (mx[x] + mx2[x] + 1 >= k) {
                res++;
                dp = 0;
            }
            for (auto y: e[x]) {
                if (dp >= mx[y]) {
                    mx2[y] = mx[y];
                    mx[y] = dp;
                } else if (dp >= mx2[y]) {
                    mx2[y] = dp;
                }
            }
        }
        return ans[k] = res;
    };

    ans[1] = n;
    ans[n + 1] = 0;
    [&](this auto&& self, int l, int r) {
        if (r - l <= 1) {
            return;
        }
        if (ans[l] == ans[r]) {
            for (int i = l + 1; i < r; i++) {
                ans[i] = ans[l];
            }
            return;
        }
        
        int mid = (r - l) / 2 + l;
        ans[mid] = calc(mid);
        self(l, mid);
        self(mid, r);
    }(1, n + 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
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
