#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

std::vector<int> minp, primes, pid;

void sieve(int n)
{
    minp.assign(n + 1, 0);
    pid.assign(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
            pid[i] = primes.size() - 1;
        }
        for (auto p: primes) {
            if (1ll * i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (minp[i] == p) {
                break;
            }
        }
    }
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> val(primes.size());

    std::sort(a.begin(), a.end());
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && a[j] == a[i]) {
            j++;
        }
        int cnt = j - i;
        int x = a[i];
        // cout<<"x="<<x<<" cnt="<<cnt<<endl;
        while (x > 1) {
            int p = minp[x];
            val[pid[p]] += cnt;
            // cout<<"p="<<p<<endl;
            while (x % p == 0) {
                x /= p;
            }
        }
    }

    std::vector<i64> sum(primes.size() + 1);
    for (size_t i = 0; i < primes.size(); i++) {
        // cout<<val[i]<<" \n"[i==primes.size()-1];
        sum[i + 1] = sum[i] + val[i];
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;

        auto pl = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
        auto pr = upper_bound(primes.begin(), primes.end(), r) - primes.begin();

        i64 ans = sum[pr] - sum[pl];
        std::cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve(10000000);

    int t = 1;
    while (t--) {
        solve();    
    }

    return 0;
}