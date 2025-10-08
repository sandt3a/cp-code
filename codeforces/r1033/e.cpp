#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int L = 0, R = 1e6, best = -1;
    i64 res = 1LL << 60;
    while (L <= R) {
        int M = L + (R - L) / 2;

        int p = upper_bound(a.begin(), a.end(), M) - a.begin();
        i64 vac = i64(p) * M - pre[p];
        int q = lower_bound(a.begin(), a.end(), M + k) - a.begin();
        i64 sur = pre[n] - pre[q] - i64(n - q) * (M + k);

        if (res > max(sur, vac)) {
            res = max(sur, vac);
            best = M;
        }
        if (vac < sur) {
            L = M + 1;
        } else {
            R = M - 1;
        }
    }

    // cout<<"res="<<res<<" best="<<best<<endl;

    i64 ans = i64(res) * k;
    i64 s = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < best) {
            s += best - a[i];
            a[i] = best;
        } else if (a[i] > best + k) {
            t += a[i] - best - k;
            a[i] = best + k;
        }
        ans += i64(a[i] + 1) * a[i] / 2;
    }

    if (s > t) {
        ans -= (s - t) * (best + k);
    } else if (s < t) {
        ans += (t - s) * (best + k + 1 - k);
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

