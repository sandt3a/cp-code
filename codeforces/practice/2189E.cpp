#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    string s;

    cin >> n >> s;

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] == '1' ? 1 : -1);
    }

    auto get = [&](int l, int r) -> int { // sum of [l, r), 0-index
        return pre[r] - pre[l];
    };
    
    if (get(0, n) == -n) {
        cout << "-1\n";
        return;
    }

    int ans = 4;
    if (s == "1") {
        ans = 0;
    } else if (get(0, n) >= 0) {
        ans = 1;
    } else if ([&]() -> bool {
        for (int i = 0; i < n; i++) {
            if (get(0, i + 1) > 0) {
                return true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (get(i, n) > 0) {
                return true;
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (get(0, i + 1) == 0 && get(i + 1, n) == -1) {
                return true;
            }
            if (get(0, i + 1) == -1 && get(i + 1, n) == 0) {
                return true;
            }
        }
        return false;
    }()) {
        ans = 2;
    } else if ([&]() -> bool {
        for (int i = 0; i < n; i++) {
            if (get(0, i + 1) >= 0) {
                return true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (get(i, n) >= 0) {
                return true;
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (get(i, i + 2) == 2) {
                return true;
            }
        }
        return false;
    }()) {
        ans = 3;
    }
    cout << ans + n - 1 << "\n";
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
