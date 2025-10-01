#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 n;
    cin >> n;

    i64 val = 1;
    int B = 0;
    while (val * 3 <= n) {
        val *= 3;
        B++;
    }
    i64 ans = 0;
    for (int x = B; x >= 0; x--) {
        ans += (n / val) * (val * 3 + val / 3 * x);
        n %= val;
        val /= 3;
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
