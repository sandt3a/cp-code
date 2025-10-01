#include <bits/stdc++.h>

void solve()
{
    std::vector<int> a(5);
    std::cin >> a[0] >> a[1] >> a[3] >> a[4];

    auto calc = [&]() {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] + a[i+1] == a[i+2]) {
                cnt++;
            }
        }
        return cnt;
    };

    int ans = 0;
    for (int x = -100; x <= 100; x++) {
        a[2] = x;
        ans = std::max(ans, calc());
    }
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
