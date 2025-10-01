#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 x;
    cin >> x;

    i64 z = 10;
    while (z <= x) {
        z *= 10;
    }
    z*=10;
    z--;

    i64 y = z - x;
    // cout<<"z="<<z<<" v="<<(x * i64(z+1) + y) % (x + y)<<endl;
    // assert((x * i64(z+1) + y) % (x + y) == 0);
    cout << y << "\n";
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
