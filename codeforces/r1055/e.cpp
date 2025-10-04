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
    if (n == -1) {
        exit(-1);
    }

    const int N = n * n + 1;

    auto query = [&](const std::vector<int> &v) {
        cout << "? " << v.size();
        for (auto x: v) {
            cout << " " << x + 1;
        }
        cout << endl;

        int k;
        cin >> k;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x--;
            res.push_back(x);
        }
        return res;
    };

    vector<int> vis(N, -1);
    auto answer = [&](std::vector<int> v) {
        v.resize(n + 1);
        cout << "!";
        for (auto x: v) {
            cout << " " << x + 1;
        }
        cout << endl;
    };

    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for (int j = 0; j < N; j++) {
            if (vis[j] == -1) {
                vec.push_back(j);
            }
        }
        auto res = query(vec);
        if (res.size() > n) {
            answer(res);
            return;
        }
        for (auto x: res) {
            vis[x] = i;
        }
    }

    int st;
    for (int i = 0; i < N; i++) {
        if (vis[i] == -1) {
            vis[i] = n;
            st = i;
        }
    }

    int cur = n;
 
    vector<int> ans {st};
    for (int i = st - 1; i >= 0 && cur >= 0; i--) {
        if (vis[i] == cur - 1) {
            ans.push_back(i);
            cur--;
        }
    }
    reverse(ans.begin(), ans.end());
    answer(ans);
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