#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    std::cin >> n;

    vector<int> ans;
    vector<int> vis(1 << n);

    int f = (1 << n) - 1;
    for (int i = 0; i <= n; i++) {
        ans.push_back(f >> i);
        vis[f >> i] = true;

        for (int s = 0; s < (1 << i); s++) {
            int t = (f >> i) | (s << (n-i));
            if (vis[t]) continue;
            ans.push_back(t);
            vis[t] = true;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        if (vis[i]) {
            continue;
        }
        ans.push_back(i);
    }
    for (auto x: ans) {
        cout << x << " \n"[x == ans.back()];
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
