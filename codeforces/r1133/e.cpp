#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    i64 lim;
    cin >> n >> lim;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ranges::sort(a);

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    i64 B = i64(sqrt(lim) + 0.5);
    while (B * B >= lim) B--;
    i64 ans = pre[n - 1];

    for (int M = 1, pos = 0; M <= B; M++) {
        while (pos < n && a[pos] <= M) {
            pos++;
        }
        ans = min(ans, pre[n] - pre[pos] - i64(n - pos) * M);
    }

    for (int b = 1, pos = 0; b <= B; b++) {
        i64 cap = (lim - 1) / b;
        while (pos + 1 < n && a[pos] <= b) {
            pos++;
        }
        ans = min(ans, pre[n - 1] - pre[pos] - i64(n - 1 - pos) * b + max(0LL, a.back() - cap));
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
