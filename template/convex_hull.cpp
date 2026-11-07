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
