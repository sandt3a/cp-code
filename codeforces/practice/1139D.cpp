#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int MOD = 1e9 + 7;

i64 power_mod(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

i64 inv_mod(i64 x) {
    return power_mod(x, MOD - 2);
}

vector<int> minp, mu, prime;

void sieve(int n) {
    minp.assign(n + 1, 0);
    mu.assign(n + 1, 0);
    prime.clear();

    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            prime.push_back(i);
            minp[i] = i;
            mu[i] = -1;
        }

        for (auto p: prime) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                mu[i * p] = 0;
                break;
            }
            mu[i * p] = -mu[i];
        }
    }
}

int main()
{
    int m;
    cin >> m;

    sieve(100000);

    i64 ans = 1;
    for (int i = 2; i <= m; i++) {
        i64 p = (m / i) * inv_mod(m) % MOD;
        ans += -mu[i] * p * inv_mod(1 - p) % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}
