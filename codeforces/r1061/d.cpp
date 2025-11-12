#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

int query(int i, int x) {
    cout << "? " << i << " " << x << endl;
    int res;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;

    const int L = std::__lg(n) + 1;

    vector<int> cur;
    for (int i = 1; i < n; i++) {
        cur.push_back(i);
    }

    int ans = 0;
    for (int k = 0; k < L; k++) {
        int tot[2] = {0};
        for (int v = 1; v <= n; v++) {
            if ((v & ((1 << k) - 1)) != ans) {
                continue;
            }
            tot[v >> k & 1]++;
        }

        vector<vector<int>> res(2);

        for (auto x: cur) {
            int b = query(x, 1 << k);
            res[b].push_back(x);
        }

        for (auto b: {0, 1}) {
            if ((int)res[b].size() != tot[b]) {
                cur = res[b];
                ans |= b << k;
            }
        }
    }

    cout << "! " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
