#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(k);
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end());

    i64 ans = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0, cur = 0; i < n; i++) {
        if (cur < k && !--b[cur]) {
            cur++;
            ans -= a[i];
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
