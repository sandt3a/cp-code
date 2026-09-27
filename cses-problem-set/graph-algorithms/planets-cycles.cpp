#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

template <class F>
struct y_combinator {
    F f;

    explicit y_combinator(F _f) : f(std::move(_f)) {}

    template <class... Args>
    decltype(auto) operator()(Args&&... args) {
        return f(*this, std::forward<Args>(args)...);
    }
};

template <class F>
auto make_y(F&& f) {
    return y_combinator<std::decay_t<F>>(std::forward<F>(f));
}

void solve()
{
    int n;
    cin >> n;

    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        cin >> to[i];
        to[i]--;
    }

    vector<int> in(n);
    vector<vector<int>> from(n);
    for (int i = 0; i < n; i++) {
        from[to[i]].push_back(i);
        in[to[i]]++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            que.push(i);
        }
    }
    vector<int> vis(n);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 1;
        if (--in[to[x]] == 0) {
            que.push(to[x]);
        }
    }

    vector<int> dep(n, -1);
    vector<int> col(n);
    vector<int> tin(n), tout(n);
    int dfs_clock = 0;

    auto dfs = make_y([&](auto &&self, int x, int d, int c) -> void {
        dep[x] = d;
        col[x] = c;
        tin[x] = dfs_clock++;
        for (auto y: from[x]) {
            if (in[y]) continue;
            self(y, d + 1, c);
        }
        tout[x] = dfs_clock++;
    });

    int tot = 0, cid = 0;
    vector<int> rt(n), cyc(n, -1), clen;
    for (int i = 0; i < n; i++) {
        if (vis[i] || col[i]) continue;

        int x = i;
        int len = 0;
        do {
            rt[tot] = x;
            dfs(x, 0, tot++);
            cyc[x] = cid;
            x = to[x];
            len++;
        } while (x != i);
        clen.push_back(len);
        cid++;
    }

    for (int i = 0; i < n; i++) {
        cout << dep[i] + clen[cyc[rt[col[i]]]] << " \n"[i == n - 1];
    }
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
