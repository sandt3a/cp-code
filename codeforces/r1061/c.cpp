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
    }

    sort(a.begin(), a.end());

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int s = 0;
        for (int j = i; j < 4 * i && j <= n; j += i) {
            s += cnt[j];
        }

        int p = n - (int)(lower_bound(a.begin(), a.end(), 4 * i) - a.begin());
        //cout<<"i="<<i<<" s="<<s<<" p="<<p<<endl;

        if (n - s - p <= k) {
            ans = max(ans, i);
        }
    }

    cout << ans << "\n";
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
