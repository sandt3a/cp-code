#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> cnt;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cnt[y]++;
    }

    if (n == 1) {
        cout << (cnt[1] % 2 ? "Mimo" : "Yuyu") << "\n";
    } else {
        for (auto [key, val]: cnt) {
            if (key == 0) continue;
            if (val % 2) {
                cout << "Mimo\n";
                return;
            }
        }
        cout << "Yuyu\n";
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
