#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MAXC = 2e5 + 5;

void solve()
{
    int n, y;
    cin >> n >> y;

    int maxc = 2;
    vector<int> c(n);
    vector<int> cnt(MAXC);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cnt[c[i]]++;

        maxc = max(c[i], maxc);
    }

    for (int i = 1; i < MAXC; i++) {
        cnt[i] += cnt[i - 1];
    }

    auto get = [&](int l, int r) {
        assert(0 < l && l <= r);
        return cnt[min(r, maxc)] - cnt[l - 1];
    };

    i64 ans = -i64(n) * y;
    for (int x = 2; x <= maxc; x++) {
        i64 res = 0;
        for (int i = 1; i <= maxc / x + 1; i++) {
            int r = get(i * x - x + 1, i * x);
            int cc = min(r, get(i, i));
            // cout<<"x="<<x<< " i="<<i<<" r="<<r<< " cnt="<<get(i, i)<<" sell="<<i64(r) * i<<" cost="<<i64(r - cc) * y<<endl;
            res += i64(r) * i - i64(r - cc) * y;
        }
        // cout<<"x="<<x<<" res="<<res<<endl;
        ans = max(ans, res);
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
