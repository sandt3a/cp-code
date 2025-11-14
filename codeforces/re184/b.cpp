#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    string s;
    cin >> s;
    // cout<<"s="<<s<<endl;

    int n = s.length();

    vector<vector<int>> e(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') {
            if (i > 0) {
                e[i].push_back(i - 1);
                in[i-1]++;
            }
        } else if (s[i] == '>') {
            if (i + 1 < n) {
                e[i].push_back(i + 1);
                in[i+1]++;
            }
        } else {
            if (i > 0) {
                e[i].push_back(i - 1);
                in[i-1]++;
            }
            if (i + 1 < n) {
                e[i].push_back(i + 1);
                in[i+1]++;
            }
        }
    }

    vector<int> vis(n);
    const int inf = 0x3f3f3f3f;
    vector<int> dis(n, 0);

    std::function<bool(int)> dfs = [&](int x) -> bool {
        // cout<<"x="<<x<<endl;
        if (vis[x] == -1) return false;
        if (vis[x] == 1) return true;
        vis[x] = -1;
        for (auto y: e[x]) {
            if (!dfs(y)) {
                return false;
            }
            dis[x] = max(dis[x], dis[y] + 1);
        }
        return vis[x] = 1;
    };

    // cout<<"?"<<endl;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (!dfs(i)) {
            cout << "-1" << endl;
            return;
        }
    }
    int ans = *max_element(dis.begin(), dis.end());
    cout << ans + 1 << endl;
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
