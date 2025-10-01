#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
    } else if (a % b == 0 || b % a == 0) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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
