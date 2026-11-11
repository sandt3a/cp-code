#include <bits/stdc++.h>
#include <cassert>
using namespace std;

namespace rgs = ranges;

using i64 = long long;
using u64 = unsigned long long;
using r64 = long double;

struct Point {
    int x, y;
};
Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}
ostream& operator<<(ostream &out, Point p) {
    return out << p.x << " " << p.y;
}

i64 sqr(i64 x) {
    return x * x;
}
i64 cross(Point a, Point b) {
    return i64(a.y) * b.x - i64(a.x) * b.y;
}
i64 area2(Point a, Point b, Point c) {
    return abs(cross(a - c, b - c));
}

struct Line {
    int a, b;
    r64 k;
};

r64 slope(Point a, Point b) {
    if (a.x == b.x) return 1e20;
    return r64(a.y - b.y) / (a.x - b.x);
}

void solve()
{
    int n;
    i64 S;
    cin >> n >> S;
    S *= 2;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    // 【修复 1】：先把点按 (x, y) 排序！
    // 这样当 i > j 时，p[i].x >= p[j].x，向量 p[i] - p[j] 永远朝右，方向绝不会反！
    rgs::sort(p, [](Point a, Point b) {
        return tie(a.x, a.y) < tie(b.x, b.y);
    });

    vector<Line> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            vec.push_back({i, j, slope(p[i], p[j])});
        }
    }

    rgs::sort(vec, [&](const Line &a, const Line &b) {
        return a.k < b.k;
    });

    Line l0 = vec[0];
    auto get = [&](Point pts) {
        return cross(pts - p[l0.a], p[l0.a] - p[l0.b]);
    };

    // 【修复 2】：因为 p 已经按 (x, y) 排好，对应 k = -inf 时的顺序就是 0, 1, ..., n-1
    // 不需要再用 vec[0] 去 sort，避免了 vec[0] 两个端点 get() 相等导致顺序颠倒的 bug！
    vector<int> ord(n), pos(n);
    rgs::iota(ord, 0);
    rgs::iota(pos, 0);

    for (auto l: vec) {
        l0 = l;
        auto [u, v, _] = l;
        vector<int> ws;
        for (auto val: {-S, S}) {
            auto bisect = [&](int l, int r) {
                while (l <= r) {
                    int m = std::midpoint(l, r);
                    auto gm = get(p[ord[m]]);
                    if (gm == val) return m;
                    if (gm < val) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
                return -1;
            };

            int w = bisect(0, n - 1);
            if (w != -1) {
                ws.push_back(ord[w]);
            }
        }

        for (auto w: ws) {
            if (area2(p[u], p[v], p[w]) == S) {
                cout << "Yes\n";
                cout << p[u] << "\n" << p[v] << "\n" << p[w] << "\n";
                return;
            }
        }

        swap(pos[u], pos[v]);
        swap(ord[pos[u]], ord[pos[v]]);
    }

    cout << "No\n";
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
