#include <bits/stdc++.h>
using namespace std;

using i64 = int;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int inf = 1 << 30;

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

vector<pair<i64, int>> factor(i64 n) {
    if (n == 1) {
        return {};
    }
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

auto divisor(i64 n) {
    auto d = factor(n);

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

    sort(res.begin(), res.end());

    return res;
};

struct Hash {
    i64 operator()(const vector<pair<i64, int>> &d) const {
        i64 res = 1;
        for (auto [x, t]: d) {
            for (int i = 0; i < t; i++) {
                res *= x;
            }
        }
        return res;
    }
} h;

unordered_map<vector<pair<i64, int>>, unordered_map<int, int>, Hash> dp;

int dfs(vector<pair<i64, int>> d, int a) {
    if (a == 1) {
        return 0;
    }
    if (h(d) == 1) {
        return a - 1;
    }
    //cout<<"d="<<h(d)<<" a="<<a<<endl;
    if (dp.count(d) && dp[d].count(a)) {
        return dp[d][a];
    }
    int &res = dp[d][a];
    res = a - 1;
    for (auto &[x, t]: d) {
        if (t == 0) continue;
        t--;
        int r = a % x;
        res = min(res, dfs(d, a / x) + r + 1);
        if (r) {
            res = min(res, dfs(d, a / x + 1) + x - r + 1);
        }
        t++;
    }
    return res;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }
    if (b - a == 1) {
        cout << a - 1 << endl;
        return;
    }
    auto d = factor(b - a);

    int ans = dfs(d, a);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1000000);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
