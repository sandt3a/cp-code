#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    i64 n;
    cin >> n;

    if (n % 2 == 0) {
        i64 a = n / 2;
        cout << "Yes\n";
        cout << a << " " << a << endl;
    } else {
        cout << "No\n";
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
