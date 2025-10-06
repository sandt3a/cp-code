#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> op(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        op[i].resize(k);

        for (int j = 0; j < k; j++) {
            cin >> op[i][j];
            op[i][j]--;
        }
    }

    vector<int> tag(m);
    int T = 0;
    for (auto vec: op) {
        T++;
        for (auto x: vec) {
            tag[x] = T;
        }
    }

    vector<int> vis(m);
    auto inter = [&](const vector<int> &a, const vector<int> &b, int bid) {
        T++;
        for (auto x: a) {
            vis[x] = T;
        }
        for (auto y: b) {
            if (vis[y] == T && tag[y] == bid) {
                return true;
            }
        }
        return false;
    };

    for (int i = 0; i + 1 < n; i++) {
        if (!inter(op[i], op[i + 1], i + 2)) {
            cout << "Yes\n";
            for (int j = 0; j < i; j++) {
                cout << j + 1 << " ";
            }
            cout << i + 2 << " " << i + 1;
            for (int j = i + 2; j < n; j++) {
                cout << " " << j + 1;
            }
            cout << "\n";
            return;
        }
    }

    cout << "No\n";
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
