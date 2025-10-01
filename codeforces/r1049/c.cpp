#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto b = a;
    auto c = a;
    for (int i = 0; i < n; i++) {
        b[i] = 2*a[i] - i;
        c[i] = 2*a[i] + i;
    }

    vector<i64> p, q, r, s;

    i64 ans = 0, sign = 1;
    for (int i = 0; i < n; i++, sign = -sign) {
        ans += a[i] * sign;
        if (sign == 1) {
            p.push_back(b[i]);
            q.push_back(c[i]);
        } else {
            r.push_back(b[i]);
            s.push_back(c[i]);
        }
    }

    auto calc = [](vector<i64> &a, vector<i64> &b) -> i64 {
        if (a.empty() || b.empty()) return 0LL;
        auto x = min_element(a.begin(), a.end()) - a.begin();
        auto y = max_element(b.begin(), b.end()) - b.begin();
        return b[y] - a[x];
    };

    i64 val = max(calc(p, r), calc(q, s));
    if (n & 1) {
        val = max<i64>(val, n - 1);
    } else {
        val = max<i64>(val, n - 2);
    }
    cout << ans + val << "\n";
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
