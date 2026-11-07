#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;

    int p = query(1, n);
    if (p == n || p == 0) {
        cout << "! NO" << endl;
        return;
    }
    int cnt = query(1, p);
    cout << "! ";
    if (cnt == p) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    cout.flush();
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
