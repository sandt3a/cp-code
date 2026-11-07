#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
i64 lim;
vector<int> a, x;
i64 best;

void dfs(int idx, i64 ops) {
    if (ops >= best) return;
    if (idx == n) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((i64)x[i] * x[j] >= lim) return;
        best = ops;
        return;
    }
    for (int v = a[idx]; v >= 0; v--) {
        x[idx] = v;
        dfs(idx + 1, ops + (a[idx] - v));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> lim;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        x.assign(n, 0);
        best = accumulate(a.begin(), a.end(), 0LL);
        dfs(0, 0);
        cout << best << "\n";
    }
    return 0;
}
