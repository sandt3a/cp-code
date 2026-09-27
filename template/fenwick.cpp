template<class T>
struct Fenwick {
    int n;
    vector<T> d;

    Fenwick(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        d.assign(n + 1, T());
    }

    void add(int x, const T& v = 1) {
        for (int i = x; i <= n; i += i & -i) {
            d[i] += v;
        }
    }

    T sum(int x) const {
        T res = 0;
        for (int i = x; i; i -= i & -i) {
            res += d[i];
        }
        return res;
    }
};
