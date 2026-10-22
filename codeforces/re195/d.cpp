#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (e[i].empty()) {
            cout << "Brain Melt\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        if ((int)e[i].size() == n - 1 && m == n - 1) {
            cout << "2\n";
            return;
        }
    }


    cout << "Many\n";
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
