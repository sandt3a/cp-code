#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    i64 sum = std::accumulate(p.begin(), p.end(), 0LL);
    i64 ans = sum;
    for (int s = 0; s < (1 << n); s++) {
        i64 a = 0;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                a += p[i];
            }
        }
        i64 b = sum - a;
        i64 diff = std::abs(a - b);
        ans = min(ans, diff);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
