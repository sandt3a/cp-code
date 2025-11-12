#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int MOD = 998244353;

vector<i64> fac;

void init(int n = 100000) {
    fac.assign(n + 1, 0);

    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        e[p[i]].push_back(i);
    }

    vector<int> sz(n, 1);
    for (int i = n - 1; i >= 1; i--) {
        sz[p[i]] += sz[i];
    }

    vector<vector<int>> ee(n);
    vector<int> ssz(n);

    i64 ans = 1;
    for (int i = 0; i < n; i++) {
        sort(e[i].begin(), e[i].end(), [&](int x, int y) {
            return sz[x] > sz[y];
        });

        int m = (int)e[i].size();
        for (int j = 0; j < m; ) {
            int k = j;
            while (k < m && sz[e[i][k]] == sz[e[i][j]]) {
                k++;
            }

            ans = ans * fac[k - j] % MOD;

            j = k;
        }

        int pre = i;
        for (int j = 0; j < m; j++) {
            ee[pre].push_back(e[i][j]);
            pre = e[i][j];
        }
    }

    auto get_sz = [&](auto &&self, int x, int p) -> int {
        ssz[x] = 1;
        for (auto y: ee[x]) {
            if (y == p) continue;
            ssz[x] += self(self, y, x);
        }
        return ssz[x];
    };

    get_sz(get_sz, 0, -1);
    cout << accumulate(ssz.begin(), ssz.end(), 0LL) << endl;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
