#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = "#" + s + "#";

    vector<array<int, 10>> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        pre[i][s[i] - '0'] = i;
    }

    vector<array<int, 10>> nxt(n + 2);
    nxt[n + 1].fill(n + 1);
    for (int i = n; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - '0'] = i;
    }

    vector<int> d(n + 2);
    vector<int> dd(n + 3);

    for (int i = 1; i <= n; i++) {
        int p = i, q = i;
        for (int x: {2, 0, 2, 5}) {
            p = nxt[p][x];
        }
        for (int x: {2, 0, 2, 6}) {
            q = nxt[q][x];
        }
        if (p < q) {
            dd[i] += q - p;
            dd[i + 1] -= q - p;
            dd[p + 1] -= 1;
            dd[q + 1] += 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + dd[i];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += d[i];
        i64 cur = i64(i) * (n + 1 - i) - ans;
        cout << cur << " \n"[i == n];
    }
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
