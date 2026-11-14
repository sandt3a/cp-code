#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> nxt(n, -1);
    vector<vector<int>> g(n);

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.back()] < a[i]) {
            nxt[stk.back()] = i;
            g[i].push_back(stk.back());
            stk.pop_back();
        }
        stk.push_back(i);
    }
    
    vector<i64> len(n);
    vector<i64> sum(n);
    vector<int> red(n);

    i64 ans = i64(n) * (n - 1) / 2;
    auto dfs = [&](this auto &&self, int x, int top) -> void {
        ans += sum[x];
        // println("x,sum={},{}\n",x,sum);
        for (auto y: g[x]) {
            bool is_red = y != g[x].back();
            red[y] = red[x] + is_red;
                
            int diff = x - y;
            len[y] = len[x] + diff;

            if (top == -1) {
                sum[y] = sum[x] + len[x] + 2 * diff - 1;
            } else {
                sum[y] = sum[top] + 2 * len[top] + (3 * (top - x) - red[nxt[x]] - 1) + 2 * diff - 1;
            }
            self(y, max(top, is_red ? x : -1));
        }
    };

    for (auto x: stk) {
        dfs(x, -1);
    }
    cout << ans << "\n";
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
