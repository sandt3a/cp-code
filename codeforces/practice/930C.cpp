#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    std::vector<int> d(m + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        d[l] += 1;
        d[r] -= 1;
    }

    std::vector<int> val(m);
    for (int i = 0, cur = 0; i < m; i++) {
        cur += d[i];
        val[i] = cur;
    }

    auto work = [&]() {
        vector<int> dp;
        vector<int> res(m);

        for (int i = 0; i < m; i++) {
            auto it = upper_bound(dp.begin(), dp.end(), val[i]);
            if (it == dp.end()) {
                dp.push_back(val[i]);
            } else {
                *it = val[i];
            }
            res[i] = dp.size();
            if (i) {
                res[i] = max(res[i], res[i - 1]);
            }
        }
        return res;
    };

    auto LIS = work();

    for (int i = 0; i < m; i++) {
        val[i] = -val[i];
    }
    auto LDS = work();

    std::reverse(val.begin(), val.end());
    auto rLDS = work();
    std::reverse(rLDS.begin(), rLDS.end());

    for (int i = 0; i < m; i++) {
        val[i] = -val[i];
    }
    auto rLIS = work();
    std::reverse(rLIS.begin(), rLIS.end());

    // cout<<"LIS:";
    // for (auto x: LIS) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    // cout<<"rLIS:";
    // for (auto x: rLIS) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;


    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (i + 1 < m) {
            ans = max(ans, LIS[i] + rLIS[i + 1]);
        } else {
            ans = max(ans, LIS[i]);
        }
        // ans = min(ans, LDS[i] + rLIS[i] - 1);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
