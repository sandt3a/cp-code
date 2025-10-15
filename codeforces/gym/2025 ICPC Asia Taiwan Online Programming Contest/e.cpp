#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

struct DSU {
    vector<int> fa, sz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        fa.resize(n);
        sz.assign(n, 1);
        iota(fa.begin(), fa.end(), 0);
    };

    int get(int x) {
        if (x == fa[x]) {
            return x;
        }
        return fa[x] = get(fa[x]);
    }

    int getsz(int x) {
        return sz[get(x)];
    }

    bool merge(int x, int y) {
        x = get(x);
        y = get(y);

        if (x == y) {
            return false;
        }
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        fa[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
        return true;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<array<int, 2>> p(k);
    vector<vector<int>> id(n, vector<int> (m));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        id[x][y] = i + 1;
        p[i] = {x, y};
    }

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    x0--;
    y0--;

    auto encode = [&](int x, int y) {
        return x * m + y;
    };

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    DSU ss(n * m);
    int tot = 0;
    for (auto [x, y]: p) {
        ss.sz[encode(x, y)] = 0;
        if (x0 <= x && x < x1 && y0 <= y && y < y1) {
            tot++;
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (id[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (id[nx][ny]) continue;
                ss.merge(encode(x, y), encode(nx, ny));
            }
        }
    }

    const int aim = (x1 - x0) * (y1 - y0);
    if (tot == 0 && ss.getsz(encode(x0, y0)) >= aim) {
        cout << "0\n";
        return;
    }

    for (auto [x, y]: p) {
        if (x0 <= x && x < x1 && y0 <= y && y < y1) {
            tot--;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (id[nx][ny] < id[x][y]) {
                ss.merge(encode(x, y), encode(nx, ny));
            }
        }
        //cout << ss.getsz(encode(x, y)) << endl;
        if (tot == 0 && ss.getsz(encode(x0, y0)) >= aim) {
            cout << id[x][y] << "\n";
            return;
        }
    }

    cout << "-1\n";
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
