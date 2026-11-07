#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long long;

struct Point {
    r64 x, y;

    Point& operator+=(const Point &rhs) & {
        x += rhs.x, y += rhs.y;
        return *this;
    }
    Point& operator-=(const Point &rhs) & {
        x -= rhs.x, y -= rhs.y;
        return *this;
    }
    friend Point operator+(Point a, const Point &b) {
        return a += b;
    };
    friend Point operator-(Point a, const Point &b) {
        return a -= b;
    };
    friend bool operator==(const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    friend istream& operator>>(istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream &out, const Point &p) {
        return out << "(" << p.x << ", " << p.y << ")";
    }
    friend bool operator<(const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

r64 dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
r64 cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

vector<Point> get_hull(vector<Point> p) {
    if (p.empty()) return p;
    sort(p.begin(), p.end(), [&](const Point &a, const Point &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    });

    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1u) {
        return p;
    }

    vector<Point> h;
    for (auto pp: p) {
        while (h.size() >= 2u && cross(pp - h[h.size() - 2], pp - h.back()) <= 0) {
            h.pop_back();
        }
        h.push_back(pp);
    }
    ranges::reverse(p);
    auto lim = h.size();
    for (auto pp: p) {
        while (h.size() >= lim + 1u && cross(pp - h[h.size() - 2], pp - h.back()) <= 0) {
            h.pop_back();
        }
        h.push_back(pp);
    }

    if (h.size() > 1u) {
        h.pop_back();
    }
    return h;
}
// 在逆时针凸包 P[0..n-1] 上寻找关于偏序 better 的全局极值点
// better(i, j) 当且仅当顶点 i 严格优于顶点 j 时返回 true
int extreme_vertex(int n, auto&& better) {
    if (n == 1) return 0;
    bool up0 = better(1, 0);
    if (!up0 && !better(n - 1, 0)) return 0; // 0 本身就是峰值点

    int l = 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        bool up_m = better((mid + 1) % n, mid);
        if (up0 ? (up_m && !better(0, mid)) : (up_m || !better(mid, 0))) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

void solve()
{
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    auto h = get_hull(p);

    if (h.size() <= 2u) {
        cout << "-1\n";
        return;
    }

    set<Point> ss(h.begin(), h.end());
    vector<Point> inner;
    for (auto pp: p) {
        if (!ss.count(pp)) {
            inner.push_back(pp);
        }
    }
    auto g = get_hull(inner);

    if (g.empty()) {
        cout << "-1\n";
        return;
    }

    i64 base = 0;
    for (size_t i = 1; i + 1 < h.size(); i++) {
        base += cross(h[i] - h[0], h[i + 1] - h[0]);
    }

    i64 ans = 0;
    for (size_t i = 0; i < h.size(); ++i) {
        Point A = h[i], B = h[(i+1) % h.size()];
        int j = extreme_vertex((int)g.size(), [&](int u, int v) {
            return cross(B - A, g[u] - A) < cross(B - A, g[v] - A);
        });
        ans = max(ans, base - cross(B - A, g[j] - A));
    }
    cout << ans << "\n";
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
