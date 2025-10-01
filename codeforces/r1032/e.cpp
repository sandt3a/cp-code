#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

std::mt19937 rnd(std::random_device{}());

int randint(int l, int r) {
    return l + rnd() % (r - l + 1);
}

int f(int x, int y) 
{
    int res = 0;
    while (x || y) {
        res += x % 10 == y % 10;
        x /= 10;
        y /= 10;
    }
    return res;
}

void solve()
{
    int l, r;
    cin >> l >> r;

    int ans = f(l, l) + f(l, r);
    for (int i = 0; i < 1000; i++) {
        int x = randint(l, r);
        ans = min(ans, f(l, x) + f(x, r));
    }
    cout << ans << endl;
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
