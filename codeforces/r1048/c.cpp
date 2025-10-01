#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 k, x;
    cin >> k >> x;

    i64 y = (1LL << (k + 1)) - x;
    i64 ans = k;
    while ((x&1) == 0 && (y&1) == 0) {
        x >>= 1;
        y >>= 1;
        ans--;
    }

    vector<int> o(ans);
    while (x != y) {
        if (x < y) {
            y -= x;
            x <<= 1;
            o.push_back(1);
        } else {
            x -= y;
            y <<= 1;
            o.push_back(2);
        }
    }
    reverse(o.begin(), o.end());

    cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        cout << o[i] << " ";
    }
    cout << "\n";
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
