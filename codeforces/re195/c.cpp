#include <bits/stdc++.h>
#include <cassert>
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

    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    i64 ans = 0;
    vector<int> cnt(k);
    for (int r = 1; r <= n; r++) {
        if (r - k - 1 >= 0) {
            cnt[pre[r - k - 1] % k]++;
        }
        ans += cnt[pre[r] % k];
        //cout<<"r="<<r<<" ans="<<ans<<endl;
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
