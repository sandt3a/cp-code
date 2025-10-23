#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

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

    vector<int> vis(n, -1);
    vector<int> deg(n, -1);
    vector<array<int, 2>> edge;

    std::mt19937 rng(random_device{}());
    //std::mt19937 rng;

    for (int _ = 0; _ < 100; _++) {
        edge.clear();

        std::function<void(int, int)> dfs = [&](int x, int p) {
          //  cout<<"x="<<x<<endl;
            vis[x] = _;
            deg[x] = 0;
            if (p != -1) {
                deg[p]++;
                deg[x]++;
                edge.push_back({p, x});
            }

            shuffle(e[x].begin(), e[x].end(), rng);
            for (auto y: e[x]) {
                if (vis[y] == _) {
                    continue;
                }
                if (deg[x] + 1 > n / 2) {
                    break;
                }
                dfs(y, x);
            }
        };

        dfs(int(rng() % n), -1);

        if ((int)edge.size() == n - 1) {
            cout << "Yes\n";
            for (auto [x, y]: edge) {
                cout << x + 1 << " " << y + 1 << "\n";
            }
            return;
        }
    }

    cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
