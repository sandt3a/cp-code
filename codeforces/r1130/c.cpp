#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int INF = 0x3f3f3f3f;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](int k) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int d = INF;
            if (i) d = min(d, a[i] - a[i - 1]);
            if (i + 1 < n) d = min(d, a[i + 1] - a[i]);
            if (d > k) {
                cnt++;
                if (i + 1 < n && a[i + 1] - a[i] <= 2 * k) {
                    i++;
                }
            }
        }
        return cnt <= x;
    };

    int L = 1, R = a.back(), ans = -1;
    while (L <= R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            R = M - 1;
            ans = M;
        } else {
            L = M + 1;
        }
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
