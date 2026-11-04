#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

template<class T>
struct Point {
    T x;
    T y;
    Point(const T &x_ = 0, const T &y_ = 0) : x(x_), y(y_) {}
    
    template<class U>
    operator Point<U>() {
        return Point<U>(U(x), U(y));
    }
    Point &operator+=(const Point &p) & {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) & {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const T &v) & {
        x *= v;
        y *= v;
        return *this;
    }
    Point &operator/=(const T &v) & {
        x /= v;
        y /= v;
        return *this;
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, const Point &b) {
        return a += b;
    }
    friend Point operator-(Point a, const Point &b) {
        return a -= b;
    }
    friend Point operator*(Point a, const T &b) {
        return a *= b;
    }
    friend Point operator/(Point a, const T &b) {
        return a /= b;
    }
    friend Point operator*(const T &a, Point b) {
        return b *= a;
    }
    friend bool operator==(const Point &a, const Point &b) {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream &operator>>(std::istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class T>
struct Line {
    Point<T> a;
    Point<T> b;
    Line(const Point<T> &a_ = Point<T>(), const Point<T> &b_ = Point<T>()) : a(a_), b(b_) {}
};

template<class T>
T dot(const Point<T> &a, const Point<T> &b) {
    return a.x * b.x + a.y * b.y;
}

template<class T>
T cross(const Point<T> &a, const Point<T> &b) {
    return a.x * b.y - a.y * b.x;
}

template<class T>
T square(const Point<T> &p) {
    return dot(p, p);
}

template<class T>
double length(const Point<T> &p) {
    return std::sqrt(square(p));
}

template<class T>
double length(const Line<T> &l) {
    return length(l.a - l.b);
}

template<class T>
Point<T> normalize(const Point<T> &p) {
    return p / length(p);
}

template<class T>
bool parallel(const Line<T> &l1, const Line<T> &l2) {
    return cross(l1.b - l1.a, l2.b - l2.a) == 0;
}

template<class T>
double distance(const Point<T> &a, const Point<T> &b) {
    return length(a - b);
}

template<class T>
double distancePL(const Point<T> &p, const Line<T> &l) {
    return std::abs(cross(l.a - l.b, l.a - p)) / length(l);
}

template<class T>
double distancePS(const Point<T> &p, const Line<T> &l) {
    if (dot(p - l.a, l.b - l.a) < 0) {
        return distance(p, l.a);
    }
    if (dot(p - l.b, l.a - l.b) < 0) {
        return distance(p, l.b);
    }
    return distancePL(p, l);
}

template<class T>
Point<T> rotate(const Point<T> &a) {
    return Point(-a.y, a.x);
}

template<class T>
int sgn(const Point<T> &a) {
    return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1;
}

template<class T>
bool pointOnLineLeft(const Point<T> &p, const Line<T> &l) {
    return cross(l.b - l.a, p - l.a) > 0;
}

template<class T>
Point<T> lineIntersection(const Line<T> &l1, const Line<T> &l2) {
    return l1.a + (l1.b - l1.a) * (cross(l2.b - l2.a, l1.a - l2.a) / cross(l2.b - l2.a, l1.a - l1.b));
}

template<class T>
bool pointOnSegment(const Point<T> &p, const Line<T> &l) {
    return cross(p - l.a, l.b - l.a) == 0 && std::min(l.a.x, l.b.x) <= p.x && p.x <= std::max(l.a.x, l.b.x)
        && std::min(l.a.y, l.b.y) <= p.y && p.y <= std::max(l.a.y, l.b.y);
}

template<class T>
bool pointInPolygon(const Point<T> &a, const std::vector<Point<T>> &p) {
    int n = (int)p.size();
    for (int i = 0; i < n; i++) {
        if (pointOnSegment(a, Line(p[i], p[(i + 1) % n]))) {
            return false;
        }
    }
    
    int t = 0;
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        if (u.x < a.x && v.x >= a.x && pointOnLineLeft(a, Line(v, u))) {
            t ^= 1;
        }
        if (u.x >= a.x && v.x < a.x && pointOnLineLeft(a, Line(u, v))) {
            t ^= 1;
        }
    }
    
    return t == 1;
}

// 0 : not intersect
// 1 : strictly intersect
// 2 : overlap
// 3 : intersect at endpoint
template<class T>
std::tuple<int, Point<T>, Point<T>> segmentIntersection(const Line<T> &l1, const Line<T> &l2) {
    if (std::max(l1.a.x, l1.b.x) < std::min(l2.a.x, l2.b.x)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::min(l1.a.x, l1.b.x) > std::max(l2.a.x, l2.b.x)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::max(l1.a.y, l1.b.y) < std::min(l2.a.y, l2.b.y)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (std::min(l1.a.y, l1.b.y) > std::max(l2.a.y, l2.b.y)) {
        return {0, Point<T>(), Point<T>()};
    }
    if (cross(l1.b - l1.a, l2.b - l2.a) == 0) {
        if (cross(l1.b - l1.a, l2.a - l1.a) != 0) {
            return {0, Point<T>(), Point<T>()};
        } else {
            auto maxx1 = std::max(l1.a.x, l1.b.x);
            auto minx1 = std::min(l1.a.x, l1.b.x);
            auto maxy1 = std::max(l1.a.y, l1.b.y);
            auto miny1 = std::min(l1.a.y, l1.b.y);
            auto maxx2 = std::max(l2.a.x, l2.b.x);
            auto minx2 = std::min(l2.a.x, l2.b.x);
            auto maxy2 = std::max(l2.a.y, l2.b.y);
            auto miny2 = std::min(l2.a.y, l2.b.y);
            Point<T> p1(std::max(minx1, minx2), std::max(miny1, miny2));
            Point<T> p2(std::min(maxx1, maxx2), std::min(maxy1, maxy2));
            if (!pointOnSegment(p1, l1)) {
                std::swap(p1.y, p2.y);
            }
            if (p1 == p2) {
                return {3, p1, p2};
            } else {
                return {2, p1, p2};
            }
        }
    }
    auto cp1 = cross(l2.a - l1.a, l2.b - l1.a);
    auto cp2 = cross(l2.a - l1.b, l2.b - l1.b);
    auto cp3 = cross(l1.a - l2.a, l1.b - l2.a);
    auto cp4 = cross(l1.a - l2.b, l1.b - l2.b);
    
    if ((cp1 > 0 && cp2 > 0) || (cp1 < 0 && cp2 < 0) || (cp3 > 0 && cp4 > 0) || (cp3 < 0 && cp4 < 0)) {
        return {0, Point<T>(), Point<T>()};
    }
    
    Point p = lineIntersection(l1, l2);
    if (cp1 != 0 && cp2 != 0 && cp3 != 0 && cp4 != 0) {
        return {1, p, p};
    } else {
        return {3, p, p};
    }
}

template<class T>
double distanceSS(const Line<T> &l1, const Line<T> &l2) {
    if (std::get<0>(segmentIntersection(l1, l2)) != 0) {
        return 0.0;
    }
    return std::min({distancePS(l1.a, l2), distancePS(l1.b, l2), distancePS(l2.a, l1), distancePS(l2.b, l1)});
}

template<class T>
bool segmentInPolygon(const Line<T> &l, const std::vector<Point<T>> &p) {
    int n = p.size();
    if (!pointInPolygon(l.a, p)) {
        return false;
    }
    if (!pointInPolygon(l.b, p)) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        auto u = p[i];
        auto v = p[(i + 1) % n];
        auto w = p[(i + 2) % n];
        auto [t, p1, p2] = segmentIntersection(l, Line(u, v));
        
        if (t == 1) {
            return false;
        }
        if (t == 0) {
            continue;
        }
        if (t == 2) {
            if (pointOnSegment(v, l) && v != l.a && v != l.b) {
                if (cross(v - u, w - v) > 0) {
                    return false;
                }
            }
        } else {
            if (p1 != u && p1 != v) {
                if (pointOnLineLeft(l.a, Line(v, u))
                    || pointOnLineLeft(l.b, Line(v, u))) {
                    return false;
                }
            } else if (p1 == v) {
                if (l.a == v) {
                    if (pointOnLineLeft(u, l)) {
                        if (pointOnLineLeft(w, l)
                            && pointOnLineLeft(w, Line(u, v))) {
                            return false;
                        }
                    } else {
                        if (pointOnLineLeft(w, l)
                            || pointOnLineLeft(w, Line(u, v))) {
                            return false;
                        }
                    }
                } else if (l.b == v) {
                    if (pointOnLineLeft(u, Line(l.b, l.a))) {
                        if (pointOnLineLeft(w, Line(l.b, l.a))
                            && pointOnLineLeft(w, Line(u, v))) {
                            return false;
                        }
                    } else {
                        if (pointOnLineLeft(w, Line(l.b, l.a))
                            || pointOnLineLeft(w, Line(u, v))) {
                            return false;
                        }
                    }
                } else {
                    if (pointOnLineLeft(u, l)) {
                        if (pointOnLineLeft(w, Line(l.b, l.a))
                            || pointOnLineLeft(w, Line(u, v))) {
                            return false;
                        }
                    } else {
                        if (pointOnLineLeft(w, l)
                            || pointOnLineLeft(w, Line(u, v))) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

using Real = long long;
using P = Point<Real>;

constexpr Real eps = 0;

vector<P> convex_hull(vector<P> a) {
    sort(a.begin(), a.end(), [&](P aa, P bb) {
        if (aa.x != bb.x) {
            return aa.x < bb.x;
        }
        return aa.y < bb.y;
    });
    a.erase(unique(a.begin(), a.end()), a.end());

    if (a.size() <= 1u) {
        return a;
    }

    int tot = 0;
    vector<P> vec;
    for (auto p: a) {
        while (tot > 1 && cross(p - vec[tot - 1], p - vec[tot - 2]) >= 0) {
            vec.pop_back();
            tot--;
        }
        tot++;
        vec.push_back(p);
    }

    int lim = tot;
    ranges::reverse(a);
    for (auto p: a) {
        while (tot > lim && cross(p - vec[tot - 1], p - vec[tot - 2]) >= 0) {
            vec.pop_back();
            tot--;
        }
        vec.push_back(p);
        tot++;
    }

    if (vec.size() > 1u) {
        vec.pop_back();
    }
    return vec;
}

struct Hash {
    u64 operator()(const P& p) const {
        return ((u64)(p.x + 1000000000) << 32) | (u64)(p.y + 1000000000);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<P> a(n);
    unordered_map<P, int, Hash> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        mp[a[i]] = i;
    }

    vector<P> points(q);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    auto p = convex_hull(a);

    if (p.size() < 3u) {
        for (int i = 0; i < q; i++) {
            cout << "-1\n";
        }
        return;
    }

    P O = p[0];
    auto ang = [&](P aa) {
        if (aa == O) return -1e18L;
        auto pp = aa - O;
        return atan2l(pp.y, pp.x);
    };

    vector<int> ord;
    for (int i = 0; i < q; i++) {
        if (points[i] != O && ang(points[i]) < ang(p.back())) {
            ord.push_back(i);
        }
    }
    
    bool flag = false;
    P ext;
    if (p.size() == 4u) {
        flag = true;
        for (int i = 0; i < n; i++) {
            if (!pointOnSegment(a[i], Line(p[0], p[2]))
                    && !pointOnSegment(a[i], Line(p[1], p[3]))) {
                flag = false;
                ext = a[i];
                break;
            }
        }
    }

    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return ang(points[x]) < ang(points[y]);
    });

    int l = 0;
    int r = 1;

    vector<vector<int>> ans(q);

    for (int i = 0; i < (int)ord.size(); i++) {
        int id = ord[i];
        auto pts = points[id];

        while (l + 1 < (int)p.size() && ang(p[l + 1]) <= ang(pts)) l++;
        while (r < (int)p.size() && ang(p[r]) < ang(pts)) r++;
        assert(l <= r);

        if (l == r) {
            if (!pointOnSegment(pts, Line(O, p[l])) || pts == O || pts == p[l]) {
                continue;
            }
            if (l == 1 || l == (int)p.size() - 1) {
                continue;
            }
            if (flag && p.size() == 4u) {
                if (pointOnSegment(pts, Line(p[0], p[2])) &&
                        pointOnSegment(pts, Line(p[1], p[3]))) {
                    ans[id] = {mp[p[0]], mp[p[1]], mp[p[2]], mp[p[3]]};
                    continue;
                }
            }

            vector<P> A = {O, p[l - 1], p[r + 1]};
            vector<P> B = {p[1], p[l], p.back()};
            if (pointInPolygon(pts, A)) {
                ans[id] = {mp[O], mp[p[l - 1]], mp[p[r + 1]]};
            } else if (pointInPolygon(pts, B)) {
                ans[id] = {mp[p[1]], mp[p[l]], mp[p.back()]};
            } else {
                assert(p.size() == 4u);
                for (int j = 0; j < 4; j++) {
                    int k = (j + 1) % 4;
                    vector<P> C = {ext, p[j], p[k]};
                    if (pointInPolygon(pts, C)) {
                        ans[id] = {mp[ext], mp[p[j]], mp[p[k]]};
                        break;
                    }
                }
            }
        } else {
            vector<P> A = {O, p[l], p[r]};
            if (pointInPolygon(pts, A)) {
                ans[id] = {mp[O], mp[p[l]], mp[p[r]]};
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i].empty()) {
            cout << "-1\n";
        } else {
            int s = (int)ans[i].size();
            cout << s << "\n";
            for (int j = 0; j < s; j++) {
                cout << ans[i][j] + 1 << " \n"[j == s - 1];
            }
        }
    }
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
