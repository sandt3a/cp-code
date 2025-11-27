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

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int xsum = 0;
    for (int i = 0; i < n; i++) {
        xsum ^= a[i] ^ b[i];
    }
    int bit = -1;
    for (int i = 30; i >= 0; i--) {
        if (xsum >> i & 1) {
            bit = i;
            break;
        }
    }
    if (bit == -1) {
        cout << "Tie\n";
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        if ((a[i] ^ b[i]) >> bit & 1) {
            cout << (i % 2 ? "Mai" : "Ajisai") << "\n";
            return;
        }
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
