#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    vector<int> vis(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            cnt++;
        } else if (a[i] < k) {
            vis[a[i]] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (!vis[i]) {
            ans++;
        }
    }
    ans = max(ans, cnt);

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
