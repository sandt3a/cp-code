#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    using State = array<bool, 3>;

    std::function<State(int, int)> dfs = [&](int x, int p) -> State {
        bool leaf = true;
        State cur{1, 0, 0};
        for (auto y: e[x]) {
            if (y == p) continue;
            leaf = false;

            auto res = dfs(y, x);
       // cout<<"y="<<y<<"state=" << res[0] << res[1] << res[2] << endl;

            State ncur{0,0,0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ncur[(i + j) % 3] |= cur[i] && res[j];
                }
            }
            cur = ncur;
        //cout<<"x="<<x<<"state=" << cur[0] << cur[1] << cur[2] << endl;
        }

        if (leaf) {
            return State{0, 1, 0};
        }

        cur[1] = true;
        return cur;
    };

    auto dp = dfs(0, -1);
    if (dp[0]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
