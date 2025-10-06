#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;

    vector<array<int, 2>> a;
    vector<array<int, 2>> b;
    for (int i = 0; i < n; i++) {
        int c, w, f;
        cin >> c >> w >> f;
        if (w == 1) {
            b.push_back({f, c});
        } else {
            a.push_back({f, c});
        }
    }

    vector<int> d;

    sort(b.begin(), b.end(), greater<>());
    for (auto [f, c]: b) {
        if (c & 1) {
            d.push_back(f);
        }
        if (c / 2) {
            a.push_back({f, c / 2});
        }
    }
    sort(d.begin(), d.end(), greater<>());
    int sz = (int)d.size();
    for (int i = 0; i < sz; i += 2) {
        a.push_back({d[i], 1});
    }

    n = (int)a.size();
    sort(a.begin(), a.end(), greater<>());

    //assert(k % 2 == 0);
    k /= 2;
    i64 ans = 0;
    for (int i = 0; i < n;) {
        i64 space = k;
        int j = i;
        while (j < n && a[j][1] <= space) {
            space -= a[j][1];
            j++;
        }

        if (i == j) {
            //assert(space == k);
            i64 t = a[i][1] / k;
            ans += a[i][0] * t;
            a[i][1] %= (int)k;
            if (a[i][1] == 0) {
                i++;
            }
        } else {
            if (j < n) {
                a[j][1] -= (int)space;
            }
            ans += a[i][0];
            i = j;
        }
    }

    cout << ans << "\n";
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
