#include <bits/stdc++.h>
#include <cassert>
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

    auto check = [&](int gap) -> bool {
        int l = -1;
        int r = -1;
        for (int i = 0; i + 1 < n; i++) {
            int d = abs(a[i + 1] - a[i]);
            if (d > gap) {
                if (l == -1) {
                    l = i;
                } else if (r == -1) {
                    r = i;
                } else {
                    return false;
                }
            }
        }
        if (l == -1) return true;
        if (r == -1) {
            bool ok = false;

            for (int x = l; x >= 0; x--) {
                if (x + 1 <= l && abs(a[x + 1] - a[x]) * 2 > gap) break;
                if ((x - 1 < 0 || abs(a[x - 1] - a[l] * 2) <= gap) && abs(a[l + 1] - a[x] * 2) <= gap) {
                    ok = true;
                }
            }

            for (int x = l + 1; x < n; x++) {
                if (x > l + 1 && abs(a[x] - a[x - 1]) * 2 > gap) break;
                if (abs(a[l] - a[x] * 2) <= gap && (x + 1 >= n || abs(a[l + 1] * 2 - a[x + 1]) <= gap)) {
                    ok = true;
                }
            }

            return ok;
        }
        auto b = a;
        reverse(b.begin() + l + 1, b.begin() + r + 1);
        for (int i = l + 1; i <= r; i++) {
            b[i] *= 2;
        }
        for (int i = 0; i + 1 < n; i++) {
            int d = abs(b[i + 1] - b[i]);
            if (d > gap) {
                return false;
            }
        }
        return true;
    };

    int L = 0, R = 1e6, ans = -1;
    while (L <= R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            ans = M;
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    cout << ans << "\n";
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
