#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int a, b;
    cin >> a >> b;

    vector<int> ans;
    //for (int i = 30; i >= 0; i--) {
    for (int i = 0; i < 31; i++) {
        if ((a ^ b) >> i & 1) {
            int t = 1 << i;
            if (t > a) {
                cout << "-1\n";
                return;
            }
            ans.push_back(t);
            a ^= t;
        }
    }

    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " \n"[x == ans.back()];
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
