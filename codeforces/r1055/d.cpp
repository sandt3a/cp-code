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

    auto calc = [&](int x) {
        int res = 0;
        while (true) {
            x >>= 1;
            res++;
            if (x == 1) {
                break;
            }
            x += 1;
        }
        return res;
    };

    vector<int> pre(n + 1);
    vector<int> cnt3(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + calc(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cnt3[i + 1] = cnt3[i] + calc(a[i] + 1) - calc(a[i]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        int ans = pre[r] - pre[l];
        ans += (cnt3[r] - cnt3[l]) / 2;

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