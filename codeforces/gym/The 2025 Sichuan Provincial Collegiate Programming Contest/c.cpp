#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r18 = long double;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<r18> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);

    // vector<vector<int>> d(n + 1);
    vector<vector<int>> s(n + 1);

    for (int i = 1; i <= n; i++) {
        s[i].push_back(i);
        for (int j = i * 2; j <= n; j += i) {
            s[j].push_back(i);
            s[i].push_back(j);
        }
    }

    // for (auto v: s) {
    //     for (auto x: v) {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    for (int _ = 0; _ < 100; _++) {
        auto nans = ans;
        for (int i = 1; i <= n; i++) {
            r18 avg = 0;
            for (auto j: s[i]) {
                avg += ans[j - 1];
            }
            avg /= s[i].size();
            nans[i] = min(ans[i - 1], avg) + 1;
        }
        ans = nans;
    }

    cout << fixed << setprecision(12);
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
