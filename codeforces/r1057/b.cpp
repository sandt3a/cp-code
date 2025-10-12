#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 inf = 1LL << 60;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;

    if (set({x & y, y & z, z & x}).size() > 1u) {
        cout << "NO\n";
        return;
    }

    for (int i = 30; i >= 0; i--) {
        int cnt = 0;
        for (int n: {x, y, z}) {
            cnt += n >> i & 1;
        }
        if (cnt == 2) {
            cout << "NO\n";
            return;
        }
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
