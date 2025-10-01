#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string ans(n, '1');

    vector<int> pre_min(n, 10000000);
    vector<int> suf_max(n, 0);
    for (int i = 0; i < n; i++) {
        pre_min[i] = i ? min(pre_min[i - 1], a[i]) : a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf_max[i] = i+1<n ? max(suf_max[i + 1], a[i]) : a[i];
    }

    for (int i = 0; i < n; i++) {
        if (pre_min[i] < a[i] && a[i] < suf_max[i]) {
            ans[i] = '0';
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
