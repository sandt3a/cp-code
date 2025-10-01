#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;

    std::vector<vector<int>> e(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    vector<pair<int, int>> dis;
    auto bfs = [&](int s) -> int {
        queue<int> q;
        vector<int> inq(n);
        dis.assign(n, {-1, -1});

        dis[s] = {0, -1};
        q.push(s);
        inq[s] = true;

        int x;
        while (!q.empty()) {
            x = q.front();
            q.pop();
            inq[x] = false;

            auto [d, from] = dis[x];
            for (auto y: e[x]) {
                if (dis[y].first == -1 || dis[y].first > d + 1) {
                    dis[y] = {d + 1, x};
                    if (!inq[y]) {
                        inq[y] = true;
                        q.push(y);
                    }
                }
            }
        }
        return x;
    };

    int st = bfs(0);
    int ed = bfs(st);

    vector<int> on_dia(n);

    for (int cur = ed; cur != -1; cur = dis[cur].second) {
        on_dia[cur] = true;
    }

    vector<int> vec;
    for (int i = 0; i < n; i++) {
        if (e[i].size() > 2u && on_dia[i]) {
            vec.push_back(i);
        }
    }

    sort(vec.begin(), vec.end(), [&](int x, int y) {
        return dis[x] < dis[y];
    });

    if (vec.empty()) {
        cout << -1 << "\n";
    } else {
        int a = -1;
        int b = vec[0];
        int c = dis[b].second;

        for (auto y: e[b]) {
            if (y != c && !on_dia[y]) {
                a = y;
                break;
            }
        }
        swap(a, c);

        cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
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
