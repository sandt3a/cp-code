// ODT / Chtholly tree on the fixed domain [0, n).
//   assign(l, r, v):     set [l, r) to v
//   enumerate(l, r, f):  f(int l, int r, T v) for each interval
//   apply(l, r, f):      f(T &v) for each interval, may modify v
template<class T>
struct ODT {
    struct Node {
        int l, r;
        mutable T v;

        bool operator<(const Node &rhs) const {
            return l < rhs.l;
        }
    };

    int n;
    std::set<Node> s;

    ODT(int n_, T v = T()) : n(n_) {
        s.insert({0, n, v});
    }

    // Return an iterator to the interval starting at x, splitting if needed.
    auto split(int x) {
        if (x <= 0) {
            return s.begin();
        }
        if (x >= n) {
            return s.end();
        }
        auto it = std::prev(s.upper_bound({x, 0, T()}));
        if (it->l == x) {
            return it;
        }
        auto [l, r, v] = *it;
        s.erase(it);
        s.insert({l, x, v});
        return s.insert({x, r, v}).first;
    }

    void assign(int l, int r, T v) {
        if (l >= r) {
            return;
        }
        auto itr = split(r);
        auto itl = split(l);
        s.erase(itl, itr);
        s.insert({l, r, v});
    }

    template<class F>
    void enumerate(int l, int r, F f) {
        if (l >= r) {
            return;
        }
        auto itr = split(r);
        for (auto it = split(l); it != itr; ++it) {
            f(it->l, it->r, it->v);
        }
    }

    template<class F>
    void apply(int l, int r, F f) {
        if (l >= r) {
            return;
        }
        auto itr = split(r);
        for (auto it = split(l); it != itr; ++it) {
            f(it->v);
        }
    }
};
