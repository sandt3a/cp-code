#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 ans = 0;

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            if (a[i - 1] >= a[i]) {
                ans += a[i - 1] - a[i];
                a[i - 1] = a[i];
            }
            if (i + 1 < n && a[i - 1] + a[i + 1] >= a[i]) {
                ans += a[i - 1] + a[i + 1] - a[i];
                a[i + 1] = a[i] - a[i - 1];
            }
        }
    }

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
