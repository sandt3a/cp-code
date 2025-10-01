#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<i64> pre(n + 1);
    vector<i64> cnt(n + 1);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + c[i] - 1;
        cnt[i + 1] = cnt[i] + (c[i] == 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        l--;

        if (r - l >= 2 && pre[r] - pre[l] >= cnt[r] - cnt[l]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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
