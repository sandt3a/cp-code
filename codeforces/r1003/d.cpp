#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<i64> a(n);

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 s = 0;
        i64 ssum = 0;
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
            s += v[j];
            ssum += s;
        }
        a[i] = s;
        ans += ssum;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        ans += a[i] * m * (n-i-1);
    }
    cout << ans << "\n";
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
