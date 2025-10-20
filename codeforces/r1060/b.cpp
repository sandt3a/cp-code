#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], b[i]);
    }

    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1 && b[i - 1] >= b[i]) {
            b[i] = max(b[i], pre[i]);
            if (b[i - 1] >= b[i]) {
                ans += b[i - 1] - b[i] + 1;
                b[i - 1] = b[i] - 1;
            }
        } else if (i % 2 == 0 && b[i - 1] <= b[i]) {
            b[i] = max(b[i], pre[i]);
            if (b[i - 1] <= b[i]) {
                ans += b[i] - b[i - 1] + 1;
                b[i] = b[i - 1] - 1;
            }
        } else if (i % 2 == 1) {
            b[i] = max(b[i], pre[i]);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " \n"[i == n - 1];
    // }

    cout << ans << '\n';
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
