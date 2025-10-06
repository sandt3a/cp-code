#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    const int A = n * m;

    vector<int> a(n * m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i * m + j] = (s[j] == 'O');
        }
        // cout<<s<<endl;
    }

    vector<int> kgr;
    for (int i = 0; i < A; i++) {
        if (a[i] == 0) {
            kgr.push_back(i);
        }
    }
    // for (auto x: kgr) {
    //     cout<<x<<" ";
    // }
    // cout<<endl;

    vector<vector<int>> mem(A, vector<int>(A, -1));
    vector<bool> ok(A * A);
    std::function<bool(int, int, int)> dfs = [&](int p, int q, int tag) -> bool {
        // cout<<"p="<<p<<" q="<<q<<endl;
        auto &res = mem[p][q];
        if (res != -1) {
            return ok[res];
        }
        res = tag;

        auto get = [&](int p, int d) {        
            const int dx[] = {0, 1, 0, -1};
            const int dy[] = {1, 0, -1, 0};

            int x = p / m;
            int y = p % m;
            x += dx[d];
            y += dy[d];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                return -1;
            }
            return x * m + y;
        };

        for (int d = 0; d < 4; d++) {
            int np = get(p, d);
            int nq = get(q, d);
            if (np == -1 || a[np] == 1) continue;
            if (nq == -1 || a[nq] == 1) {
                return ok[tag] = true;
            };
            if (mem[np][nq] == tag) continue;
            if (dfs(np, nq, tag)) {
                return ok[tag] = true;
            }
        }
        return false;
    };

    const int K = kgr.size();
    int ans = 0;
    for (int i = 0; i < K; i++) {
        bool ok = true;
        for (int j = 0; j < K; j++) {
            if (i == j) continue;
            // cout<<"i="<<i<<" j="<<j<<" r="<<dfs(i,j)<<endl;
            if (!dfs(kgr[i], kgr[j], i * K + j)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
