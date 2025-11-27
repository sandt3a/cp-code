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

    vector<int> stk;
    vector<array<int, 2>> edges;
    for (int i = 0; i < n; i++) {
        if (stk.empty() || a[stk.back()] > a[i]) {
            stk.push_back(i);
        } else {
            auto it = lower_bound(stk.begin(), stk.end(), i, [&](int x, int y) {
                return a[x] > a[y]; });
            for (auto jt = it; jt != stk.end(); jt++) {
                edges.push_back({a[i], a[*jt]});
            }
            auto bk = stk.back();
            stk.erase(it, stk.end());
            stk.push_back(bk);
        }
    }

    if (stk.size() == 1u) {
        cout << "Yes\n";
        for (auto [x, y]: edges) {
            cout << x << " " << y << "\n";
        }
    } else {
        cout << "No\n";
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
