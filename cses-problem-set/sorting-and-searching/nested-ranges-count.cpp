#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using Intv = array<int, 2>;

void solve()
{
    int n;
    cin >> n;

    vector<Intv> intv;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        intv[i] = {x, y};
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
