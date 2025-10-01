#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 n, k;
    cin >> n >> k;

    i64 val = 1;
    int B = 0;
    while (val * 3 <= n) {
        val *= 3;
        B++;
    }
    i64 ans = 0;
    vector<array<i64, 3>> vec;
    for (int x = B; x >= 0; x--) {
        ans += (n / val) * (val * 3 + val / 3 * x);
        vec.push_back({n / val, x, val});
        k -= n / val;
        n %= val;
        val /= 3;
    }
    if (k < 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < (int)vec.size(); i++) {
        auto [c, x, val] = vec[i];
        if (k >= c * 2 && x) {
            ans -= c * (val * 3 + val / 3 * x);
            k -= c * 2;
            vec[i + 1][0] += c * 3;
            ans += c*3 * (val + val / 9 * (x-1));
        } else {
            if (x) {
                auto cc = min(k/2, c);
                ans -= cc * (val * 3 + val / 3 * x);
                k -= cc * 2;
                vec[i + 1][0] += cc * 3;
                ans += cc*3 * (val + val / 9 * (x-1));
            }
            break;
        }
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
