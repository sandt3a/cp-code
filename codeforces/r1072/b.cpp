#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int s, k, m;
    cin >> s >> k >> m;

    int q = m / k;
    int r = m % k;
    if (k >= s) k = s;
    if (q % 2 == 0) {
        cout << max(0, s - r) << "\n";
    } else {
        cout << max(0, k - r) << "\n";
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
