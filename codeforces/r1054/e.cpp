#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto val = a;
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (auto &x: a) {
        x = lower_bound(val.begin(), val.end(), x) - val.begin();
    }

    // g(x, k) = #(len <= x, cnt >= k)
    auto g = [&](int x, int y) -> i64 {
        deque<int> q {};
        vector<int> cnt(val.size());
        i64 res = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += cnt[a[i]] == 0;
            cnt[a[i]]++;
            q.push_back(i);
            while (q.size() && ((i - q.front() > x) || (cnt[a[q.front()]] >= 2) || tot > y)) {
                cnt[a[q.front()]]--;
                tot -= cnt[a[q.front()]] == 0;
                q.pop_front();
            }
            if (q.size() && tot == y) {
                res += abs(max(-1, i - x) - q.front());
            }
        }
        return res;
    };

    // f(x, k) = #(len <= x, cnt == k)
    auto f = [&](int x, int y) -> i64 {
        return g(x, y) - g(x, y + 1);
    };

    i64 ans = f(r, k) - f(l - 1, k);

    cout << ans << "\n";
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
