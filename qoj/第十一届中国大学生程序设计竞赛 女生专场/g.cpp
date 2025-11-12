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

    vector<int> ans {1};
    vector<bool> vis(n + 1);
    for (int i = 2; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        ans.push_back(i);
        for (int j = i + i; j <= n; j += i) {
            vis[j] = true;
        }
    }

    if ((int)ans.size() < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k - 1];
    }

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
