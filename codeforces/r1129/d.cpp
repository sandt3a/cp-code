#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

map<i64, i64> mp;
set<array<i64, 2>> vis;
const i64 LIM = 10000;

using State = array<i64, 3>;

void init()
{
    mp[0] = 0;

    priority_queue<State, vector<State>, greater<>> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        auto [v, x, cnt] = q.top();
        q.pop();
        if (abs(x) > LIM) continue;
        if (vis.count({x, cnt})) continue;
        vis.insert({x, cnt});

        i64 y = x + (1 << cnt);
        if (!mp.count(y)) {
            mp[y] = v + 1;
        } else {
            mp[y] = min(mp[y], v + 1);
        }
        q.push({v + 1, y, cnt + 1});

        i64 z = x - 1;
        if (!mp.count(z)) {
            mp[z] = v + 1;
        } else {
            mp[z] = min(mp[z], v + 1);
        }
        q.push({v + 1, z, 0});
    }

    for (auto [k, v]: mp) {
        if (k < 0) continue;
        cout << "k="<<bitset<20>(k)<<" v="<<v<<"\n";
    }
}

void solve()
{
    i64 l, r;
    cin >> l >> r;
    cout << 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
