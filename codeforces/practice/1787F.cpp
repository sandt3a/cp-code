#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

i64 power(i64 x, i64 y, i64 m) {
    i64 res = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            res = res * x % m;
        }
        x = x * x % m;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<vector<int>> cyc(n + 1);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int x = i;
        int len = 0;
        while (!vis[x]) {
            vis[x] = true;
            len++;
            x = p[x];
        }
        cyc[len].push_back(i);
        //cout<<"i="<<i<<" len="<<len<<endl;
    }

    auto merge = [&](vector<int> st, int cnt) -> vector<int> {
        vector<vector<int>> tmp(cnt);

        for (int i = 0; i < cnt; i++) {
            tmp[i].push_back(st[i]);
            for (int x = p[st[i]]; x != st[i]; x = p[x]) {
                tmp[i].push_back(x);
            }
        }

        int len = tmp[0].size();
        int delta = power(2, k - __builtin_ctz(cnt), len);
        for (auto &vec: tmp) {
            vector<int> f(len);
            for (int i = 0; i < len; i++) {
                f[i64(i) * delta % len] = vec[i];
            }
            vec = f;
        }

        for (int step = 1; step < cnt; step <<= 1) {
            for (int i = 0; i + step < cnt; i += step) {
                int j = i + step;
                vector<int> nt;
                int l = (int)tmp[i].size();
                for (int o = 0; o < l; o++) {
                    nt.push_back(tmp[i][o]);
                    nt.push_back(tmp[j][o]);
                }
                tmp[i] = nt;
            }
        }
        return tmp[0];
    };

    vector<int> ans(n);

    const int K = 1 << min(k, 20);
    for (int l = 1; l <= n; l++) {
        if (l % 2 == 0 && cyc[l].size() % K != 0) {
            cout << "NO\n";
            return;
        }
        int cnt = K;
        while (cyc[l].size()) {
            while (cnt && (int)cyc[l].size() < cnt) {
                cnt >>= 1;
            }
            assert(cnt > 0);
            auto vec = merge(vector(cyc[l].end() - cnt, cyc[l].end()), cnt);
            cyc[l].erase(cyc[l].end() - cnt, cyc[l].end());

            for (int i = 0; i < (int)vec.size(); i++) {
                ans[vec[i]] = vec[(i + 1) % vec.size()];
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
