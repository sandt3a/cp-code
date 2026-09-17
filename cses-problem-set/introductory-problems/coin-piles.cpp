#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int a, b;
    cin >> a >> b;

    int s = a + b;
    if (s % 3 == 0 && a <= b * 2 && b <= a * 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
