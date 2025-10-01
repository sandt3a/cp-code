#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }

    vector<array<int, 2>> vec;

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        auto [l, r] = a[i];
        ans += r - l;
        ans += r;
        vec.push_back({l + r, r});
    }

    sort(vec.begin(), vec.end());

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + vec[i][0];
    }

    int k = n / 2;
    i64 val = pre[k];
    if (n & 1) {
        val = 1LL << 60;
        for (int i = 0; i < n; i++) {
            auto [v, r] = vec[i];
            val = min(val, i <= k ? pre[k + 1] - v + r : pre[k] + r);
        }
    }

    cout << ans - val << "\n";
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
