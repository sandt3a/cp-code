#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 n;
    cin >> n;

    vector<i64> ans;
    for (i64 x = 10; x <= n; x *= 10) {
        if (n % (x + 1) == 0) {
            ans.push_back(n / (x + 1));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " \n"[x == ans.back()];
    }
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
