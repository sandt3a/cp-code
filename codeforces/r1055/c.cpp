#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n + 1);
    vector<int> alt(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    for (int i = 1; i < n; i++) {
        alt[i + 1] = alt[i] + (a[i] != a[i - 1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        int x = pre[r] - pre[l];
        int ans = -1;
        if (x % 3 == 0 && (r - l) % 3 == 0) {
            ans = (r - l) / 3;
            if (alt[r] - alt[l + 1] == (r - l - 1)) {
                ans++;
            }
        }
        cout << ans << "\n";
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