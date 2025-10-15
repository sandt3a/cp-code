#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

vector<int> minp;
vector<int> primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p: primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

bool is_prime(int x) {
    return x >= 2 && minp[x] == x;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    cout << "NY"[b - a == 2 && is_prime(a) && is_prime(b)] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(1000000);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
