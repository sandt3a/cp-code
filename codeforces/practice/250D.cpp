#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

r64 sqr(r64 x) {
    return x * x;
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int lhs, int rhs) {
        return x[lhs] < x[rhs];
    });

    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }

    auto get = [&](int X, int Y) -> r64 {
        return sqrtl(sqr(X) + sqr(a)) + sqrtl(sqr(X - Y) + sqr(a - b));
    };

    auto binary_search = [&](int Y) -> pair<r64, int> {
        int L = 0, R = n - 1;
        int xx = -1;
        while (L <= R) {
            int M1 = L + (R - L) / 2;
            int M2 = min(M1 + 1, R);
            r64 r1 = get(x[id[M1]], Y);
            r64 r2 = get(x[id[M2]], Y);
            if (r1 < r2) {
                xx = id[M1];
                R = M2 - 1;
            } else {
                xx = id[M2];
                L = M1 + 1;
            }
        }
        return {get(x[xx], Y), xx};
    };

    r64 ans = 1e18;
    pair<int, int> choice;
    for (int i = 0; i < m; i++) {
        auto [tmp, xx] = binary_search(y[i]);
        r64 res = l[i] + tmp;
        if (ans - res > 0) {
            ans = res;
            choice = {xx, i};
        }
    }

    cout << choice.first + 1 << " " << choice.second + 1 << endl;
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
