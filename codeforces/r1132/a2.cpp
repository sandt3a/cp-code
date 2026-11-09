#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    i64 s = 0;
    for (int i = 0; i < n; i++) {
        s += 1 << a[i];
    }

    i64 cur = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (cur + (1 << a[i]) <= s / 2) {
            cur += 1 << a[i];
        }
        ans = max(ans, cur * (s - cur));
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
