vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

auto factor(i64 n) {
    vector<pair<i64, int>> d;

    for (auto p: primes) {
        if (1ll * p * p > n) break;
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                cnt++;
                n /= p;
            }
            d.push_back({p, cnt});
        }
    }

    if (n > 1) {
        d.push_back({n, 1});
    }
    return d;
}

auto merge(const vector<pair<i64, int>> &a, const vector<pair<i64, int>> &b) {
    vector<pair<i64, int>> c;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].first == b[j].first) {
            c.push_back({a[i].first, a[i].second + b[j].second});
            i++;
            j++;
        } else if (a[i].first < b[j].first) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j++]);
        }
    }
    while (i < a.size()) {
        c.push_back(a[i++]);
    }
    while (j < b.size()) {
        c.push_back(b[j++]);
    }
    return c;
}

auto divisor(const vector<pair<i64, int>> &d) {
    int sz = static_cast<int>(d.size());
    vector<i64> res;

    std::function<void(int, int, i64)> dfs = [&](int x, int y, i64 cur) {
        if (x == sz) {
            res.push_back(cur);
            return;
        }

        dfs(x + 1, 0, cur);
        if (y < d[x].second) {
            dfs(x, y + 1, cur * d[x].first);
        }
    };

    dfs(0, 0, 1);

    return res;
};
