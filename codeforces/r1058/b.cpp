#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<i64> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int tot = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int delta = b[i + 1] - b[i] - 1;
        //cout<<"i-delta="<<i-delta<<endl;
        if (delta < i) {
            a[i] = a[i - delta - 1];
        } else {
            a[i] = ++tot;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
