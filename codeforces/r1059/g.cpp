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

    if (n == 2) {
        cout << "-1\n";
    } else if (n == 3) {
        cout << "1 3\n2 3\n";
    } else if (n == 4) {
        cout << "1 2\n3 1\n4 1\n";
    } else if (n == 5) {
        cout << "1 5\n1 2\n2 3\n3 4\n";
    } else if (n == 6) {
        cout << "1 2\n2 3\n3 4\n1 6\n2 5\n";
    } else {
        i64 s = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 2 || i == n - 4) continue;
            cout << "2 " << i << "\n";
            s += 2 * i;
        }
        s += n - 4;
        cout << "1 " << n - 4 << "\n";
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
