#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int S = 21;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ok(1 << S);

    auto insert = [&](this auto&& self, int x, int idx) {
        if (ok[x] == 2) return;
        ok[x]++;
        for (int i = idx; i < S; i++) {
            if (x >> i & 1) {
                self(x ^ (1 << i), i);
            }
        }
    };

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int mask = 0;
        for (int j = S - 1; j >= 0; j--) {
            if (a[i] >> j & 1) continue;
            if (ok[mask | 1 << j] >= 2) {
                mask |= 1 << j;
                ans = max(ans, a[i] + mask);
            }
        }
        if (ok[0] >= 2) {
            ans = max(ans, a[i]);
        }
        insert(a[i], 0);
    }
    cout << ans << "\n";
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
