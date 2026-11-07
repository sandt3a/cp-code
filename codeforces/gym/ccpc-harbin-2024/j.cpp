#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const i64 oo = 1LL << 60;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<i64> a(n), cur(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur[i] = a[i];
    }
    vector<i64> x(m), t(m);
    vector<vector<i64>> vec(n);
    vector<int> idx(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> t[i];
        t[i]--;
        vec[t[i]].push_back(x[i]);
    }
    for (int i = 0; i < n; i++) {
        vec[i].push_back(oo);
    }

    set<pair<i64, int>> b;
    for (int i = 0; i < n; i++) {
        b.insert({vec[i][idx[i]], i});
    }
    i64 pos = 0;
    int j = 0;
    while (true) {
        if (b.empty()) {
            break;
        }
        int i = b.begin()->second;
        i64 lim = pos + cur[i];
        i64 sta = j < m ? x[j] : oo;
        i64 np = min(lim, sta);
        i64 d = np - pos;
        cur[i] -= d;
        //cout << "pos=" << pos << " j="<<j<<" i="<<i<<" np="<<np<<endl;
        if (np >= sta) {
            auto y = t[j];
            cur[y] = a[y];
            if (auto it = b.find({vec[y][idx[y]], y}); it != b.end()) {
                b.erase(it);
            }
            b.insert({vec[y][++idx[y]], y});
            j++;
        } else if (cur[i] == 0) {
            b.erase(b.find({vec[i][idx[i]], i}));
        }
        pos = np;
    }
    cout << pos << "\n";
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
