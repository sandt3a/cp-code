#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    i64 s;
    int x;
    cin >> n >> s >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    map<i64, int> mp;
    i64 ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            mp.clear();
            cur = i + 1;
        } else if (a[i] == x) {
            while (cur <= i) {
                mp[pre[cur]]++;
                cur++;
            }
        } else {
            // nothing
        }
        ans += mp[pre[i + 1] - s];
    }

    cout << ans << endl;
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

