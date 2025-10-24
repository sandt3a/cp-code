#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        vis[a[i]] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            break;
        }
    }
    if (ans.empty()) {
        ans = a;
    } else {
        for (int i = 0; i < n; i++) {
            if (i != ans[0] && i != a[n - 1]) {
                ans.push_back(i);
                break;
            }
        }
        ans.push_back(a.back());
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i % ans.size()] + 1 << " \n"[i == k - 1];
    }
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
