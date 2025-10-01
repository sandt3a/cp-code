#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    vector<i64> sa(n + 1), sb(m + 1);
    for (int i = 0; i < n; i++) {
        sa[i + 1] = sa[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
        sb[i + 1] = sb[i] + b[i];
    }

    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        auto calc = [&](int t) {
            return sa[t] + sb[z - t];
        };

        int L = max(0, z - y), R = min(x, z);
        int res = -1;
        while (L <= R) {
            int M1 = L+(R-L)/2;
            int M2 = min(R, M1 + 1);

            if (calc(M1) < calc(M2)) {
                res = M2;
                L = M1 + 1;
            } else {
                res = M1;
                R = M2 - 1;
            }
        }
        i64 ans = calc(res);
        cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
