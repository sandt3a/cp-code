#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

vector<int> minp, primes, pre;

void sieve(int n) {
    minp.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (minp[i] == i) {
            pre[i] = i;
        } else {
            pre[i] = pre[i - 1];
        }
    }
}

int calc(int x, int k) {
    int res = 0;
    while (x /= k) {
        res += x;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> bp;
    for (int x = 1; x * x <= n; x++) {
        bp.push_back(pre[n / x]);
    }

    i64 ans = 0;
    for (int x = n - 1; x >= 1; x--) {
        if (minp[x + 1] == x + 1) {
            break;
        }

        int res = 1e9;
        for (auto p: bp) {
            int a = calc(x, p);
            int b = calc(n, p);
            if (a != b) {
                res = min(res, a);
            }
        }

        for (auto p: primes) {
            if (p * p > m) {
                break;
            }
            int a = calc(x, p);
            int b = calc(n, p);
            for (i64 e = 1, pw = p; pw <= m; e++, pw *= p) {
                int na = a / e;
                int nb = b / e;
                if (na != nb) {
                    res = min(res, na);
                }
            }
        }
        ans += res;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1e7);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
