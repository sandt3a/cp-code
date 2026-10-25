#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    const int n = 8;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int ans = 0;
    vector<int> col(n);
    vector<int> row(n);
    vector<int> diag1(n * 2 + 5);
    vector<int> diag2(n * 2 + 5);

    auto mark = [&](int x, int y, int c) {
        row[x] = c;
        col[y] = c;
        diag1[x - y + n] = c;
        diag2[x + y] = c;
    };

    auto dfs = [&](auto &&self, int x, int y, int todo = 8) -> void {
        if (y == n) {
            self(self, x + 1, 0, todo);
            return;
        }
        if (x == n) {
            ans += todo == 0;
            return;
        }

        self(self, x, y + 1, todo);

        if (board[x][y] == '.' && !row[x] && !col[y] && !diag1[x - y + n] && !diag2[x + y]) {
            mark(x, y, 1);
            self(self, x, y + 1, todo - 1);
            mark(x, y, 0);
        }
    };

    dfs(dfs, 0, 0);

    cout << ans << endl;
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
