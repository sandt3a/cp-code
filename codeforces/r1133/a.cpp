#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int flag = 1;
    int cnt[2] = {0};
    for (int i = 0; i < n; i++) {
        cnt[a[i] % 2]++;
        cnt[b[i] % 2]--;
    }
    if (k % 2 == 1) {
        flag = cnt[0] >= 0;
    } else {
        flag = cnt[1] >= 0;
    }
    cout << (flag ? "YES" : "NO") << "\n";
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
