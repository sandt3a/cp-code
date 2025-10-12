#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 inf = 1LL << 60;

void solve()
{
    int n;
    cin >> n;

    map<int, int> cnt;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // sort(a.begin(), a.end());
    // if (accumulate(a.begin(), a.end(), 0LL) <= a.back() * 2ll) {
    //     cout << "0\n";
    //     return;
    // }

    vector<i64> odd;

    i64 ans = 0;
    int tot = 0;
    for (auto [key, val]: cnt) {
        if (val % 2 == 1) {
            odd.push_back(key);
        }
        ans += val / 2 * 2ll * key;
        tot += val / 2 * 2;
    }
    i64 delta = 0;
    sort(odd.begin(), odd.end());
    
    for (auto x: odd) {
        if (x < ans) {
            delta = max(delta, x);
        }
        auto it = lower_bound(odd.begin(), odd.end(), x + ans);
        if (it == odd.begin()) continue;
        i64 y = *std::prev(it);
        if (y > x && y - x < ans) {
            delta = max(delta, y + x);
        }
    }

    if (tot == 0) {
        ans = 0;
    } else if (tot == 2) {
        ans *= !!delta;
    }
    cout << ans + delta << "\n";
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
