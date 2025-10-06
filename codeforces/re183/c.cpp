#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<int, int> mp;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == 'a' ? 1 : -1);
    }

    if (pre[n] == 0) {
        cout << "0\n";
        return;
    }

    // pre[r] - pre[l] == pre[n]
    // pre[r] - pre[n] == pre[l]

    int ans = n;
    for (int i = 0; i < n; i++) {
        mp[-pre[i]] = i;
        int v = pre[n] - pre[i + 1];
        // cout<<"i="<<i<<" v="<<v<<endl;
        if (mp.count(v)) {
            ans = min(ans, i+1 - mp[v]);
        }
    }

    if (ans == n) {
        ans = -1;
    }
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
