#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }

    vector<int> v(n);
    set<int> ss;
    for (int i = 0; i < n; i++) {
        v[i] = a[i][0] % n;
        for (int j = 0; j < m; j++) {
            if (a[i][j] % n != v[i]) {
                cout << -1 << "\n";
                return;
            }
        }
        ss.insert(v[i]);
    }
    if ((int)ss.size() < n) {
        cout << -1 << "\n";
        return;
    }
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int x, int y) {
            return v[x] < v[y];
            });
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " \n"[i == n-1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
