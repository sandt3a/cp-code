#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

i64 get(i64 x) {
    if (x == 0) return 1;
    if (x % 3 == 0) return get(x / 3) + 1;
    return get(x - 1) + 1;
}

i64 solve(i64 l, i64 r) {
    i64 res = 0;
    // if (r - l <= 10) {
    //     for (i64 i = l; i <= r; i++) {
    //         res = max(res, get(i));
    //     }
    //     return res;
    // }
    while (l <= r && l % 3) {
        res = max(res, get(l));
        l++;
    }
    while (l <= r && r % 3 == 0) {
        res = max(res, get(r));
        r--;
    }
    if (l > r) return res;
    res = max(res, max({get(l), get(r), solve(l / 3, r / 3) + 2}));
    return res;
}

void solve()
{
    i64 l, r;
    cin >> l >> r;

    i64 ans = solve(l, r);
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // for (int i = 1; i <= 10; i++) {
    //     cout<<"i="<<i<<" get="<<get(i)<<endl;
    // }
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}