#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(n, -1);

    auto work = [&]() {
        vector<i64> pre(n + 1);
        vector<i64> same(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
            if (i + 1 < n) {
                same[i + 1] = same[i] + (a[i] != a[i + 1]);
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            int res = -1;
            if (a[i + 1] > a[i]) {
                res = 1;
            } else {
                int l = i + 2, r = n - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (pre[mid+1] - pre[i+1] > a[i] && same[mid] != same[i+1]) {
                        res = mid - i;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
            }
            if (res == -1) {
                continue;
            }
            if (ans[i] == -1 || ans[i] > res) {
                ans[i] = res;
            }
        }
    };

    reverse(a.begin(), a.end());
    work();
    reverse(a.begin(), a.end());
    reverse(ans.begin(), ans.end());
    work();

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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
