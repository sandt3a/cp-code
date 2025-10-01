#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    while (k--) {
        i64 x, y;
        cin >> x >> y;
        if ((x + y) & 1) {
            cout << "-1\n";
            continue;
        }
        const int dx[] = {1, -1, 1, -1};
        const int dy[] = {1, 1, -1, -1};

        i64 ans = -1;
        for (int i = 0; i < 4; i++) {
            i64 d = abs(x * dx[i] + y * dy[i]);
            if (d % std::gcd(n, m) == 0) {
                i64 a, b;
                i64 g = exgcd(n, m, a, b);
                i64 coef = d / g;
                a = x*dx[i] / a * a;
                i64 res = abs(2*a*n - x * dx[i])*coef;
                // cout<<"res="<<res<<endl;
                if (ans == -1 || ans > res) {
                    ans = res;
                }
            }
        }
        cout << ans << "\n";
    }

    // (x, y) -> (2n-x, y) -> (2n+x, y) -> (4n-x, y)
    // (x, y) -> (2an +- x, 2bm +- y)
    // 2an - x == 2bm + y
    // an-bm == (y+x) / 2
    // a>=0,b>=0
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}