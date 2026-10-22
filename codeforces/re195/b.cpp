#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    string s;
    cin >> s;

    int n = (int)s.size();
    int ans = 1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1] && s[i] == s[i - 1]) {
            ans++;
            break;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1] && s[i - 1] != s[i]) {
            ans++;
            break;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
