#include <bits/stdc++.h>
#include <cassert>
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

    if (k == 1) {
        cout << -1 << "\n";
        return;
    }

    int L = n - k + 1;
    int x = max_element(a.begin(), a.begin() + L) - a.begin();
    int y = min_element(a.begin() + L, a.end()) - a.begin();
    if (a[x] > a[y]) {
        cout << x + 1 << " " << y + 1 << "\n";
    } else {
        cout << -1 << "\n";
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
