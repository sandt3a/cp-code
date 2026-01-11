#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    i64 x, y;
    std::cin >> n >> x >> y;

    std::string s;
    std::cin >> s;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    auto check = [&]() -> bool {
        i64 sump = std::accumulate(p.begin(), p.end(), 0LL);
        if (x + y < sump) {
            return false;
        }

        i64 ox = 0, oy = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                ox += p[i] / 2 + 1;
            } else {
                oy += p[i] / 2 + 1;
            }
        }

        if (x < ox || y < oy) {
            return false;
        }

        if (int tmp = count(s.begin(), s.end(), '0'); tmp == n || tmp == 0) {
            if (tmp == 0) {
                return x + n <= y;
            } else {
                return x >= y + n;
            }
        }

        return true;
    };

    if (check()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
