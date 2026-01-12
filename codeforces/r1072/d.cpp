#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

vector<vector<int>> C;

void init(int n = 30) {
    C.assign(n + 1, vector<int>(n + 1, 0));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

i64 comb(int n, int m) {
    return C[n][m];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    const int d = std::__lg(n);

    auto calc = [&](int b, int t) {
        i64 res = 0;
        for (int i = 0; i <= b && i <= t; i++) {
            res += comb(b, i);
        }
        return res;
    };

    int ans = 0;
    for (int i = 0; i < d; i++) {
        ans += calc(i, k - i - 1);
    }

    if (d + 1 <= k) {
        ans++;
    }
    ans = n - ans;
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
