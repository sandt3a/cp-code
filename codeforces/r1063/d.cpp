#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<array<int, 2>> interval(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        interval[i] = {l, r};
    }
    sort(interval.begin(), interval.end());

    vector<array<int, 2>> a;
    for (int i = 0, j; i < q; i = j) {
        j = i;
        while (j < q && interval[j][0] == interval[i][0]) {
            j++;
        }
        if (!a.empty() && a.back()[0] <= interval[j - 1][0] && a.back()[1] >= interval[j - 1][1]) {
            continue;
        }
        a.push_back(interval[j - 1]);
    }

    if (a.size() == 1u && a[0][0] == 0 && a[0][1] == n) {
        cout << "! " << n << endl;
        return;
    }

    auto query = [&](int l, int r) {
        cout << "? " << l + 1 << " " << r << endl;
        int res;
        cin >> res;
        return res;
    };

    auto check = [&](int mi) {
        int x = query(0, a[mi][1]);
        int y = query(a[mi][0], n);
        return make_pair(min(x, y), x < y);
    };

    int l = 0, r = (int)a.size() - 1, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        auto [res, ok] = check(mid);
        ans = max(ans, res);
        if (ok) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "! " << ans << endl;
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
