#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans;
    if (a[0] == -1 || a[n - 1] == -1) {
        ans = 0;
        if (a[0] != -1) {
            a[n - 1] = a[0];
        } else {
            a[0] = a[n - 1];
        }
    } else {
        ans = abs(a[n - 1] - a[0]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
