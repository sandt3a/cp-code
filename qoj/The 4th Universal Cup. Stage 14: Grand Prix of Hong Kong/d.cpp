#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<i64> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ord(n + 2);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin() + 1, ord.begin() + n + 1, [&](int x, int y) {
        return a[x] > a[y];
    });
    for (int _ = 1; _ <= n; _++) {
        int i = ord[_];
        a[i] += a[i - 1] + a[i + 1];
    }
    i64 ans = accumulate(a.begin(), a.end(), 0LL);
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
