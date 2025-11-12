#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        l[i] = max(0, 2 * a[i] - 1);
        r[i] = 2 * a[i] + 1;
        //cout << "l="<<l[i]<<" r="<<r[i]<<endl;
    }

    int L = accumulate(l.begin(), l.end(), 0);
    int R = accumulate(r.begin(), r.end(), 0);

    // l <= b/s < r
    // l*s <= b < r*s
    // L*s <= s < R*s
    // L <= 1 < R

    if (L > 200 || R <= 200) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = l[i] * (R - L)  + (r[i] - l[i]) * (200 - L);
        cout << b[i] << " \n"[i == n - 1];
    }
    cout.flush();

    auto check = [&](vector<int> v) {
        i64 s = accumulate(v.begin(), v.end(), 0LL);
        assert(s > 0);
        for (auto x: v) {
            assert(0 <= x && x < 1000000000);
        }

        for (int i = 0; i < n; i++) {
            int r = v[i] * 100.0L / s + 0.5;
            //cout<<"o="<<v[i] * 100.0L / s + 0.5<<" r="<<r<<" a="<<a[i]<<endl;
            assert(r == a[i]);
        }
    };

    check(b);
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
