#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int INF = 0x3f3f3f3f;

template<class T>
bool tense(T& x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<class T>
bool relax(T& x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<int> vis(n + 1);
    vector<int> cycs;
    int one = 0;
    int big = 0;
    int tot = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        int x = i;
        int len = 0;
        while (!vis[x]) {
            vis[x] = 1;
            len++;
            x = p[x];
        }

        if (len == 1) {
            one++;
        } else {
            cycs.push_back(len);
            tot += len;
            if (len >= 3) {
                big += len;
            }
        }
    }

    if (k == 1) {
        if (big == 0 && (one % 2 == 1 || cycs.empty())) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        return;
    }
    if (big <= k) {
        cout << "Alice\n";
        return;
    }
    
    sort(cycs.begin(), cycs.end(), greater<>());

    if (cycs[0] > k + 1) {
        cout << "Bob\n";
        return;
    }

    if (cycs[0] == k + 1) {
        if (cycs.size() >= 2u && cycs[1] == k + 1) {
            cout << "Bob\n";
        } else {
            int s = tot - cycs[0] + one % (k + 1);
            if (1 <= s && s <= k) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        }
        return;
    }

    if ((int)cycs.size() > 2 * k) {
        cycs.resize(2 * k);
    }
    vector dp(k + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;

    int id = 0;
    for (auto len: cycs) {
        if (len > k) continue;
        auto ndp = dp;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (ndp[i][j] == INF) continue;
                if (id - i < k) {
                    ndp[i][j] += len - 1;
                }
            }
        }
        for (int i = 0; i + 1 <= k; i++) {
            for (int j = 0; j + len <= k; j++) {
                if (dp[i][j] == INF) continue;
                relax(ndp[i + 1][j + len], dp[i][j]);
            }
        }
        dp = ndp;
        id++;
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] <= k) {
                cout << "Alice\n";
                return;
            }
        }
    }

    cout << "Bob\n";
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
