#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, k;
    cin >> n >> k;

    int l = n, r = n, d = 0;
    while (k < l || k > r) {
        l = l / 2;
        r = (r + 1) / 2;
        d++;
        if (l == 0 || r == 0) break;
    }

    if (l <= k && k <= r) {
        cout << d << "\n";
    } else {
        cout << "-1\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
