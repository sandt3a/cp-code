#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

i64 aim;

map<pair<i64, i64>, i64> mp;

i64 dfs(i64 hp, i64 pos) {
    if (pos == aim) {
        return 0;
    }
    if (hp == 1) {
        return (aim - pos) * 2 + 1;
    }
    if (hp == 2) {
        return (aim - pos) * 2;
    }
    if (mp.count({hp, pos})) {
        return mp[{hp, pos}];
    }

    i64 res = -1;
    for (i64 x = 1; x <= aim - pos; x++) {
        i64 c = x * (x + 1) / 2;
        if (hp <= c) break;

        i64 tmp = dfs(hp - c + 1, pos + x) + x + 1;
        if (res == -1 || res > tmp) {
            res = tmp;
        }
    }
    mp[{hp, pos}] = res;
    return res;
}

i64 get(i64 hp, i64 pos) {
    if (pos == aim) {
        cout<<"arrive"<<endl;
        return 0;
    }
    if (hp == 1) {
      cout<<"steps=1*"<<(aim-pos)<<endl;
        return (aim - pos) * 2 + 1;
    }
    if (hp == 2) {
      cout<<"steps=1*"<<(aim-pos)<<endl;
        return (aim - pos) * 2;
    }

    i64 res = mp[{hp, pos}];
    for (i64 x = 1; x <= aim - pos; x++) {
        i64 c = x * (x + 1) / 2;
        if (hp <= c) break;

        i64 tmp = dfs(hp - c + 1, pos + x) + x + 1;
        if (res == tmp) {
            cout<<"hp="<<hp<<" pos="<<pos<<" step="<<x<<endl;
            get(hp - c + 1, pos + x);
        }
    }
    return res;
}

void bf()
{
    i64 h, d;
    cin >> h >> d;

    aim = d;
    i64 ans = dfs(h, 0) - 1;

    get(h, 0);

    cout << ans << endl;
}

void solve()
{
    int h, d;
    cin >> h >> d;

    auto check = [&](int s) -> bool {
        int q = d / s;
        int r = d % s;
        i64 c1 = i64(q + 1) * (q + 2) / 2;
        i64 c2 = i64(q) * (q + 1) / 2;
        i64 t = c1 * r + c2 * (s - r);
        return t < h + s - 1;
    };

    int L = 1, R = d + 1, res = -1;
    while (L <= R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            res = M;
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    int ans = res + d;

    cout << ans - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        //bf();
        solve();
    }

    return 0;
}
