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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    auto mx = max_element(a.begin(), a.end()) - a.begin();
    auto mn = min_element(a.begin(), a.end()) - a.begin();

    if (s[0] == '1' || s.back() == '1' || s[mx] == '1' || s[mn] == '1') {
        cout << "-1\n";
        return;
    }
    vector<array<int, 2>> ans;
    ans.push_back({0, mx});
    ans.push_back({0, mn});
    ans.push_back({mx, n - 1});
    ans.push_back({mn, n - 1});
    ans.push_back({min(mx, mn), max(mx, mn)});

    cout << ans.size() << "\n";
    for (auto [l, r]: ans) {
        cout << l + 1 << " " << r + 1 << "\n";
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
