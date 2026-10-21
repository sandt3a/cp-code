#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    map<int, int> X, Y, Z;
    vector<array<int, 3>> p(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = {x, y, z};
        X[x]++;
        Y[y]++;
        Z[z]++;
    }

    vector<int> d(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        auto [x, y, z] = p[i];
        d[i] = max({X[x], Y[y], Z[z]}) - 1;
        cnt[d[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cnt[i + 1] += cnt[i];
    }

    for (int i = 0; i < n; i++) {
        cout << (i ? cnt[i - 1] : 0) << " \n"[i == n - 1];
    }
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
