#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const int offset = 1e6 + 5;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    vector<int> cnt_(offset * 2);
    auto cnt = cnt_.begin() + offset;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ans = *max_element(cnt_.begin(), cnt_.end());
    vector<int> cc_(offset * 2);
    auto cc = cc_.begin() + offset;
    vector<int> pm_(offset * 2);
    auto pm = pm_.begin() + offset;

    for (int i = 0; i < n; i++) {
        int v = a[i];
        cc[v]++;
        int u = v + k;

        if (-offset <= u && u < offset) {
            int f = cc[v] - cc[u];
            ans = max(ans, cnt[u] + f - pm[u]);
            pm[u] = min(pm[u], f);
        }

        if (-offset <= v - k && v - k < offset) {
            pm[v] = min(pm[v], cc[v - k] - cc[v]);
        }
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
