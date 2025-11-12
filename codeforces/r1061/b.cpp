#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    bool all_add = count(s.begin(), s.end(), 'A') == n;

    for (int _ = 0; _ < q; _++) {
        int x;
        cin >> x;

        int ans = 0;
        if (all_add == 1) {
            ans = x;
        } else {
            for (int i = 0; x; i++) {
                if (s[i % n] == 'A') {
                    x--;
                } else {
                    x /= 2;
                }
                ans++;
            }
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
