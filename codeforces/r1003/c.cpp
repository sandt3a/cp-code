#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    int lst = INT_MIN;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), lst + a[i]);
        int v = INT_MAX;
        if (it != b.end()) {
            v = *it - a[i];
        }
        if (a[i] >= lst) {
            v = min(v, a[i]);
        }
        if (v == INT_MAX) {
            cout << "NO\n";
            return;
        }
        lst = v;
    }
    cout << "YES\n";
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


