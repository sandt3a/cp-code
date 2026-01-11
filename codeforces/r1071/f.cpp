#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve1()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    std::vector<int> dep(n, -1);
    auto bfs = [&](int s) {
        std::queue<int> q;

        q.push(s);
        dep[s] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto y: e[x]) {
                if (dep[y] != -1) {
                    continue;
                }
                dep[y] = dep[x] + 1;
                q.push(y);
            }
        }
    };

    bfs(0);

    for (int i = 0; i < n; i++) {
        std::cout << "rgb"[dep[i] % 3];
    }
    std::cout << "\n";
}

void solve2()
{
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::cin >> n;

        std::string col;
        std::cin >> col;

        auto get = [&](int c) {
            for (int i = 0; i < 3; i++) {
                if (c == "rgb"[i]) {
                    return i;
                }
            }
            assert(false);
        };

        std::vector<int> vis(3);
        std::vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = get(col[i]);
            vis[c[i]] = true;
        }
        if (count(vis.begin(), vis.end(), 0) == 2) {
            cout << "1\n";
            continue;
        }
        int me = -1;
        for (int i = 0; i < 3; i++) {
            if (!vis[i]) {
                assert(me == -1);
                me = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if ((c[i] + 1) % 3 == me) {
                cout << i + 1 << "\n";
                goto pass;
            }
        }
        assert(false);
pass:
        ;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string op;
    std::cin >> op;
    int t = 1;
    if (op == "first") {
        std::cin >> t;
        while (t--) {
            solve1();
        }
    } else {
        std::cin >> t;
        while (t--) {
            solve2();
        }
    }

    return 0;
}
