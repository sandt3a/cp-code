#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto calc = [&](int med) -> i64 {
        // number of intervals of which medium >= med
        vector<int> b(n);
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            if (a[i] >= med) {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
            pre[i + 1] = pre[i] + b[i];
        }
        
        vector<int> _cnt(n * 2 + 5);
        auto cnt = _cnt.begin() + n + 1;

        i64 res = 0, tot = 0;
        for (int i = 0; i < n; i++) {
            cnt[pre[i]]++;
            if (b[i] == 1) {
                tot += cnt[pre[i]];
            } else {
                tot -= cnt[pre[i + 1]];
            }
            res += tot;
        }
        return res;
    };

    auto ans = calc(m) - calc(m + 1);
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
