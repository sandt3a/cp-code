#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<string> ng = grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 4; c++) {
                if (c == grid[i][j] - 'A') continue;
                if (i && c == ng[i - 1][j] - 'A') continue;
                if (j && c == ng[i][j - 1] - 'A') continue;
                ng[i][j] = c + 'A';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ng[i] << "\n";
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
