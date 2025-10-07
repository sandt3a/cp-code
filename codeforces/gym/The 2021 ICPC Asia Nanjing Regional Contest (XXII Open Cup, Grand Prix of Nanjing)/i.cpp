#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int H;
    cin >> H;
    H *= 2;

    int n;
    cin >> n;

    vector<array<int, 3>> p;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y, 0});
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y, 1});
    }

    unordered_map<int, int> dp;
    sort(p.begin(), p.end(), greater<>());
    for (auto [x, y, o]: p) {
        int a = (x + y) % H;
        int b = (x - y + H) % H;
        if (o) {
            dp[a]++;
            dp[b]++;
        } else {
            int v = max(dp[a], dp[b]);
            dp[a] = dp[b] = v;
        }
    }
    cout << dp[0] << "\n";
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
