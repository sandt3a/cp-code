#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        cin >> to[i];
        to[i]--;
    }

    constexpr int L = 31;
    vector<array<int, L>> nxt(n);
    for (int j = 0; j < L; j++) {
        if (j == 0) {
            for (int i = 0; i < n; i++) {
                nxt[i][0] = to[i];
            }
        } else {
            for (int i = 0; i < n; i++) {
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            }
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;

        for (int j = L - 1; j >= 0; j--) {
            if (k >> j & 1) {
                x = nxt[x][j];
            }
        }
        cout << x + 1 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
