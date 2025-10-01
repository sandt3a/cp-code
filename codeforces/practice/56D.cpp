#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = static_cast<int>(s.size());
    int m = static_cast<int>(t.size());

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    std::function<int(int, int)> dfs = [&](int x, int y) {
        if (x == n && y == m) {
            return 0;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        int &res = dp[x][y];
        res = 114514;

        if (x < n && y < m) {
            if (s[x] == t[y]) {
                res = min(res, dfs(x + 1, y + 1)); // NOP
            } else {
                res = min(res, dfs(x + 1, y + 1) + 1); // REPLACE s[x] t[y]
            }
        }

        if (x < n) {
            res = min(res, dfs(x + 1, y) + 1); // DELETE s[x]
        }
        if (y < m) {
            res = min(res, dfs(x, y + 1) + 1); // INSERT t[y]
        }
        return res;
    };

    vector<array<int, 3>> ans;

    std::function<void(int, int, int)> get = [&](int x, int y, int offset) {
        if (x == n && y == m) {
            return;
        }
        int res = dp[x][y];

        if (x < n && y < m) {
            if (s[x] == t[y] && res == dfs(x + 1, y + 1)) {
                get(x + 1, y + 1, offset); // nop
                return;
            } else if (res == dfs(x + 1, y + 1) + 1) {
                ans.push_back({0, x + offset, t[y]}); // REPLACE s[x] t[y]
                get(x + 1, y + 1, offset);
                return;
            }
        }

        if (x < n && res == dfs(x + 1, y) + 1) {
            ans.push_back({1, x + offset, '#'}); // DELETE s[x]
            get(x + 1, y, offset - 1);
            return;
        }
        if (y < m && res == dfs(x, y + 1) + 1) {
            ans.push_back({2, x + offset, t[y]}); // INSERT t[y]
            get(x, y + 1, offset + 1);
            return;
        }
        cout<<"?"<<endl;
        return;
    };

    dfs(0, 0);
    get(0, 0, 0);

    cout << ans.size() << "\n";

    const vector<string> ops = {"REPLACE", "DELETE", "INSERT"};

    for (auto [op, pos, ch]: ans) {
        cout << ops[op] << " " << pos + 1;
        if (op != 1) {
            cout << " " << static_cast<char>(ch);
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
