#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    map<int, int> cnt;

    auto factor = [&](int x) {
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                cnt[i]++;
                if (x / i != i) {
                    cnt[x / i]++;
                }
            }
        }
    };

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        factor(a[i]);
    }

    int ans = n - 1;
    for (auto x: a) {
        ans = min(ans, n - cnt[x]);
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
