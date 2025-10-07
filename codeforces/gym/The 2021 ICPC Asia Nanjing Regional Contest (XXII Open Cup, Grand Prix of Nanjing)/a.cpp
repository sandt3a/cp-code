#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    swap(a, b);

    int fx = 0;
    int fy = 0;
    if (a > n - a) {
        fx = 1;
        a = n + 1 - a;
    }
    if (b > n - b) {
        fy = 1;
        b = n + 1 - b;
    }

    string ans;
    for (int i = 1; i < n; i++) {
        ans += 'L';
    }
    for (int i = 1; i < n; i++) {
        ans += 'U';
    }
    for (int i = 1; i < a; i++) {
        ans += 'R';
    }
    for (int i = 1; i < b; i++) {
        ans += 'D';
    }
    int m = (int)ans.size();
    assert(m <= 3 * (n - 1));
    if (fx) {
        for (int i = 0; i < m; i++) {
            if (ans[i] == 'L') {
                ans[i] = 'R';
            } else if (ans[i] == 'R') {
                ans[i] = 'L';
            }
        }
    }
    if (fy) {
        for (int i = 0; i < m; i++) {
            if (ans[i] == 'U') {
                ans[i] = 'D';
            } else if (ans[i] == 'D') {
                ans[i] = 'U';
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
