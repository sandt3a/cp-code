#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int mod = 1e9 + 7;

i64 power(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
    }
    return res;
}

vector<i64> fac{1};
vector<i64> invfac;

i64 comb(i64 n, i64 m) {
    i64 res = 1;
    for (i64 i = n; i > n - m; i--) {
        res = res * (i % mod) % mod;
    }
    return res * invfac[m] % mod;
}

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    i64 n = (1ll*(a-1)*k+1);

    i64 m = (comb(n, a) * k % mod * (b-1) + 1) % mod;

    cout << n % mod << " " << m << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 100000;
    for (int i = 1; i <= n; i++) {
        fac.push_back(fac.back() * i % mod);
    }
    invfac.assign(n + 1, 0);
    invfac[n] = power(fac[n], mod - 2);
    for (int i = n; i >= 1; i--) {
        invfac[i - 1] = invfac[i] * i % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

