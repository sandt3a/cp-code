#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int sgn(i64 x) {
    if (x == 0) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

struct Point
{
    i64 x = 0;
    i64 y = 0;
};

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

bool operator<(Point a, Point b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

i64 det(Point a, Point b) {
    return a.y * b.x - a.x * b.y;
}

int turn(Point a, Point b, Point c) {
    return sgn(det(b - a, c - a));
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<Point, int>> p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {Point(x, y), i};
    }

    string dir;
    cin >> dir;

    sort(p.begin(), p.end());

    auto [cur, cur_id] = p[0];
    vector<int> ans { cur_id };

    vector<int> vis(n);
    vis[cur_id] = 1;
    for (int i = 0; i < n - 2; i++) {
        int d = dir[i] == 'L' ? 1 : -1;
        Point nxt;
        int nxt_id = -1;
        for (int j = 0; j < n; j++) {
            if (vis[p[j].second]) continue;

            if (nxt_id == -1) {
                tie(nxt, nxt_id) = p[j];
            } else {
                if (turn(cur, nxt, p[j].first) == d) {
                    tie(nxt, nxt_id) = p[j];
                }
            }
        }
        cur = nxt;
        vis[nxt_id] = 1;
        ans.push_back(nxt_id);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
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
