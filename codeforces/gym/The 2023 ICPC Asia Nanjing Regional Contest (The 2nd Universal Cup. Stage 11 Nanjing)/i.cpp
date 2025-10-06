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

    vector<array<int, 2>> d(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        d[i] = {a, b};
    }
    d.push_back({0, 0});
    m++;
    sort(d.begin(), d.end());

    for (int i = 1; i < m; i++) {
        auto [a, b] = d[i];
        auto [pa, pb] = d[i - 1];
        if (a == pa) {
            if (b != pb) {
                cout << "No\n";
                return;
            }
        } else {
            if (b > pb) {
                if (b - pb != a - pa && b >= a - pa) {
                    cout << "No\n";
                    return;
                }
            } else {
                if (b >= a - pa) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    cout << "Yes\n";
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
