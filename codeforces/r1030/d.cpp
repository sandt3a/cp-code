#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;

    vector<i64> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<i64> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);

    sort(id.begin(), id.end(), [&](int x, int y) { return p[x] < p[y]; });

    map<i64, vector<i64>> m1p, m2p;

    for (int i = 0; i < n; i++) {
        m1p[p[i]].push_back(p[i] - d[i]);
        m2p[p[i]].push_back(p[i] - d[i]);
    }

    auto check = [&](i64 st) -> bool {
        for (auto i: id) {
            if (p[i] >= st && (p[i] - st) % k == d[i]) {
                return ok[i];
            }
        }
        return false;
    };

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        i64 st;
        cin >> st;
        if (check(st)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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
