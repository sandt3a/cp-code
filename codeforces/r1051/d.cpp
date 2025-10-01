#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MOD = 1e9 + 7;

template<class U, class V>
void add(U &x, V y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            ::add(a[i - 1], v);
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ::add(ans, a[i - 1]);
        }
        return ans;
    }
    
    T range_sum(int l, int r) {
        return (sum(r) - sum(l) + MOD) % MOD;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    // dp[i][u][v] -> max = u, max' = v, 0 represents not exist

    dp[0][0] = 1;

    vector<Fenwick<int>> A(n + 1, Fenwick<int>(n + 1));
    vector<Fenwick<int>> B(n + 1, Fenwick<int>(n + 1));

    A[0].add(0, 1);
    B[0].add(0, 1);

    for (int i = 1; i <= n; i++) {
        vector<int> pa(n + 1);
        vector<int> pb(n + 1);
        for (int v = 0; v <= n; v++) {
            // for (int u = 0; u <= a[i]; u++) {
            //     add(ndp[a[i]][v], dp[u][v]);
            // }
            int val = A[v].sum(a[i] + 1);
            add(dp[a[i]][v], val);
            pa[v] = val;
        }
        for (int u = a[i] + 1; u <= n; u++) {
            // for (int v = 0; v <= a[i]; v++) {
            //     add(ndp[u][a[i]], dp[u][v]);
            // }
            int val = B[u].sum(a[i] + 1);
            add(dp[u][a[i]], val);
            pb[u] = val;
        }

        for (int v = 0; v <= n; v++) {
            A[v].add(a[i], pa[v]);
            B[a[i]].add(v, pa[v]);
        }
        for (int u = a[i] + 1; u <= n; u++) {
            A[a[i]].add(u, pb[u]);
            B[u].add(a[i], pb[u]);
        }
    }

    i64 ans = 0;
    for (int u = 0; u <= n; u++) {
        for (int v = 0; v <= n; v++) {
            add(ans, dp[u][v]);
        }
    }
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
