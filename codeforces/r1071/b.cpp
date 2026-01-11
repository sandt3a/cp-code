#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    i64 base = 0;
    for (int i = 0; i + 1 < n; i++) {
        base += std::abs(a[i] - a[i + 1]);
    }

    auto f = [&](int x, int y) {
        x = std::min(std::max(x, 0), n - 2);
        y = std::max(std::min(y, n - 1), x + 1);
        return std::abs(a[x] - a[y]);
    };

    //std::cout<<"base="<<base<<"\n";
    i64 ans = std::numeric_limits<i64>::max();
    for (int i = 0; i < n; i++) {
        ans = std::min(ans, base - f(i-1,i) - f(i,i+1) + f(i-1,i+1));
    }
    std::cout << ans << "\n";
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
