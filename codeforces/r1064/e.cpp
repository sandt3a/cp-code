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
    sort(a.begin(), a.end(), greater<>());

    while (q--) {
        int c;
        cin >> c;

        vector<int> b;
        for (int i = 0; i < min(n, 30); i++) {
            b.push_back(a[i]);
        }

        i64 ans = 0;
        for (int i = 30; i >= 0; i--) {
            int cnt = 0;
            for (auto &x: b) {
                cnt += x >> i & 1;
            }
            if (cnt > (c >> i & 1)) {
                break;
            }
            if (cnt < (c >> i & 1)) {
                auto it = max_element(b.begin(), b.end());
                ans += (1 << i) - *it;
                *it = 0;
            } else {
                for (auto &x: b) {
                    if (x >> i & 1) {
                        x ^= 1 << i;
                        break;
                    }
                }
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
