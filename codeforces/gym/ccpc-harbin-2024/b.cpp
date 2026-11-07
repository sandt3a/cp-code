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
    base = abs(base);

    i64 ans = 0;
    for (size_t i = 0, j = 0; i < h.size(); i++) {
        Point A = h[i];
        Point B = h[(i + 1) % h.size()];

        auto get = [&](Point C) {
            return abs(cross(A - C, B - C));
        };

        if (i == 0) {
            for (size_t k = 1; k < g.size(); k++) {
                if (get(g[k]) < get(g[j])) {
                    j = k;
                }
            }
        } else {
            while (get(g[(j + 1) % g.size()]) < get(g[j])) {
                j = (j + 1) % g.size();
            }
        }

        ans = max(ans, base - get(g[j]));
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
