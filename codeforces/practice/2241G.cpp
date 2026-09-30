#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void print(i128 x) {
    vector<int> stk;
    do {
        stk.push_back((int)(x % 10));
        x /= 10;
    } while (x);
    reverse(stk.begin(), stk.end());
    for (auto x: stk) {
        cout << x;
    }
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    srand((unsigned)time(NULL));

    const int T = 50;
    vector<vector<i64>> pre(T, vector<i64>(n + 1, 0));
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < n; i++) {
            if (rand() & 1) {
                pre[t][i + 1] = pre[t][i] + a[i];
            } else {
                pre[t][i + 1] = pre[t][i];
            }
        }
    }

    auto get = [&](int t, int l, int r) {
        return pre[t][r] - pre[t][l];
    };

    auto bisect = [&](int l, int r, int k) {
        int L = l, R = r, res = n;
        while (L <= R) {
            int M = (L + R) >> 1;
            bool ok = true;
            for (int i = 0; i < T; i++) {
                if (get(i, l, M + 1) % k) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                L = M + 1;
            } else {
                res = M;
                R = M - 1;
            }
        }
        return res;
    };

    vector<int> nxt(n, n);
    for (int i = 0; i < n; i++) {
        nxt[i] = bisect(i + 1, n - 1, a[i]);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << nxt[i] << " \n"[i == n - 1];
    // }

    i128 ans = 0;
    for (int l = 0; l < n; l++) {
        int g = a[l];
        int res = 0;
        for (int r = l + 1; r < n; r = nxt[r]) {
            res = max(res, min(g - a[r] % g, a[r] % g));
            // cout << "l="<<l<<" r="<<r<<" res="<<min(g - a[r] % g, a[r] % g)<<endl;
            if (res > 0 || g == 1) {
                ans += 1ll * res * (n - r);
                break;
            }
            g = std::gcd(g, a[r]);
        }
    }

    print(ans);
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
