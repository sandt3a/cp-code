#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if ((a % 2 == n % 2 && abs(a - b) % 2 == 0) || (b > a && b % 2 == n % 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
