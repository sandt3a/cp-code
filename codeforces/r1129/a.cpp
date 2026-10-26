#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> pre(n + 2);
    for (int i = 0; i <= n; i++) {
        pre[i + 1] = pre[i] + cnt[i];
    }
    int ans = 0;
    while (cnt[ans] && pre[ans + 1] >= k * (ans + 1)) {
        ans++;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
