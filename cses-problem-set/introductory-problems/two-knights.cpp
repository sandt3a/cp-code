#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 n;
    cin >> n;

    for (i64 k = 1; k <= n; k++) {
        i64 ans = 0;
        if (k <= 3) {
            if (k == 1) {
                ans = 0;
            } else if (k == 2) {
                ans = 6;
            } else { // k == 3
                ans = 28;
            }
        } else {
            ans = k*k * (k*k-1) / 2 -  (2*k - 4) * (k - 1) - (2*k-2) * (k - 2);
        }
        cout << ans << endl;
    }

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

