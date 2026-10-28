#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

template<class T>
bool tense(T& x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

void solve()
{
    int k;
    cin >> k;

    vector<array<int, 2>> vec;
    bool fst = true;
    array<int, 2> rt {-1, -1};
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        vector<vector<int>> e(n);
        for (int j = 0; j < n - 1; j++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        vector<array<int, 2>> dp(n);
        auto dfs = [&](this auto &&self, int x, int p) -> void {
            dp[x][0] = 0;
            dp[x][1] = 1;
            for (auto y: e[x]) {
                if (y == p) continue;
                self(y, x);

                dp[x][0] += max(dp[y][0], dp[y][1]);
                dp[x][1] += dp[y][0];
            }
        };

        dfs(0, -1);
        int ans = max(dp[0][0], dp[0][1]);
        if (ans != n && fst) {
            fst = false;
            if (ans == dp[0][0]) {
                rt = {i, 0};
            } else {
                rt = {i, e[0][0]};
            }
        } else {
            vec.push_back({i, 0});
        }
    }

    if (rt[0] == -1) {
        rt = vec.back();
        vec.pop_back();
    }

    for (auto [i, x]: vec) {
        cout << rt[0] + 1 << " " << rt[1] + 1 << " " << i + 1 << " " << x + 1 << "\n";
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
