#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> d, rd;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) {
                rd.push_back(n / i);
            }
        }
    }
    ranges::reverse(rd);
    d.insert(d.end(), rd.begin(), rd.end());

    int m = d.size();
    i64 ans = 1;
    for (int i = 1; i < m; i++) {
        i64 x = d[i] - d[i - 1];
        ans += x * (n / d[i - 1]);
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
