#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x + 1 << " \n"[x == ans.back()];
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
