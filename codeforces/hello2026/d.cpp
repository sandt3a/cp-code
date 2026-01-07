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

    vector<int> dep(n), fa(n);
    std::function<void(int, int)> dfs = [&](int x, int p) -> void {
        fa[x] = p;
        for (auto y: e[x]) {
            if (y == p) continue;
            dep[y] = dep[x] + 1;
            dfs(y, x);
        }
    };

    dfs(0, -1);

    vector<int> cnt(n);
    for (auto d: dep) {
        cnt[d]++;
    }
    int k = *max_element(cnt.begin(), cnt.end());
    for (int x = 0; x < n; x++) {
        k = max(k, (int)e[x].size() + (x == 0));
    }

    vector<vector<int>> deps(n);
    for (int i = 0; i < n; i++) {
        deps[dep[i]].push_back(i);
    }

    set<int> ss;
    for (int i = 0; i < k; i++) {
        ss.insert(i);
    }

    vector<int> col(n);

    for (int d = 0; d < n; d++) {
        int y = -1;
        //cout<<"\nd="<<d<<endl;
        for (auto x: deps[d]) {
            //cout<<"x="<<x + 1<<" ";
            bool flag = false;
            if (fa[x] != -1 && ss.count(col[fa[x]])) {
                ss.erase(col[fa[x]]);
                flag = true;
            }
            if (!ss.empty()) {
                col[x] = *ss.begin();
                ss.erase(col[x]);
                //cout<<"x="<<x<<"col="<<col[x]<<endl;
            } else {
                y = x;
            }
            if (flag) {
                ss.insert(col[fa[x]]);
            }
        }

        if (y != -1) {
            for (auto x: deps[d]) {
                if (col[fa[x]] != col[fa[y]] && col[x] != col[fa[y]]) {
                    col[y] = col[x];
                    col[x] = col[fa[y]];
                    break;
                }
            }
        }

        for (auto x: deps[d]) {
            ss.insert(col[x]);
        }
    }

    vector<vector<int>> cols(n);
    for (int i = 0; i < n; i++) {
        cols[col[i]].push_back(i);
    }

    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << cols[i].size();
        for (auto x: cols[i]) {
            cout << " " << x + 1;
        }
        cout << "\n";
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
