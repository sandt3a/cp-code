#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a;
    int len = 0;
    set<pair<int, int>> ss;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> v(k);
        for (auto &x: v) {
            cin >> x;
        }
        a.push_back(v);
        len = max(len, k);

        ss.insert({k, i});
    }

    vector<int> ans(len);
    for (int i = 0; i < len; ) {
        while (ss.begin()->first <= i) {
            ss.erase(ss.begin());
        }
        vector<int> ord;
        for (auto [_, x]: ss) {
            ord.push_back(x);
        }
        int idx = ranges::min(ord, [&](int x, int y) {
            for (int j = i; j < len; j++) {
                int X = j < ssize(a[x]) ? a[x][j] : -1;
                int Y = j < ssize(a[y]) ? a[y][j] : -1;
                if (X == -1 || Y == -1 || X != Y) {
                    return X < Y;
                }
            }
            return a[x].size() < a[y].size();
        });
        for (int j = i; j < ssize(a[idx]); j++) {
            ans[j] = a[idx][j];
        }
        i = ssize(a[idx]);
    }

    for (auto [i, x]: ans | views::enumerate) {
        cout << x << " \n"[i == len - 1];
    }
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
