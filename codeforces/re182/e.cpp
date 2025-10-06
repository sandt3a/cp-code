#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MAXC = 2e5 + 5;
const int MOD = 998244353;

template<class T>
void add(T &x, T y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto work = [&]() {
        vector<int> L;
        for (int i = 0, premax = -1; i < n; i++) {
            if (i == 0 || a[i] > premax) {
                premax = a[i];
                L.push_back(a[i]);
            }
        }
        int m = (int)L.size();
        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            if (a[i] == L[0]) {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j + 1 < m && a[i + 1] == L[j + 1]) {
                    add(dp[i + 1][j + 1], dp[i][j]);
                }
                if (a[i + 1] > L[j]) {
                    add(dp[i + 1][j], dp[i][j]);
                } else {
                    add(dp[i + 1][j], dp[i][j] * 2 % MOD);
                }
            }
        }

        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back({dp[i][m - 1], m >= 2 ? dp[i][m - 2] : 1});
        }
        return res;
    };

    auto pre = work();

    reverse(a.begin(), a.end());

    auto suf = work();

    reverse(a.begin(), a.end());
    reverse(suf.begin(), suf.end());

    i64 ans = 0;
    for (int i = 0, val = *max_element(a.begin(), a.end()); i < n; i++) {
        if (a[i] == val) {
            add(ans, 1ll * (i?pre[i - 1].second:1) * (i+1<n?(suf[i + 1].first + suf[i + 1].second):1) % MOD);
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
