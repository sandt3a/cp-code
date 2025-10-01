#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MOD = 1e9 + 7;

i64 power(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

int remove(int s, int bit) {
    return ((s >> (bit + 1)) << bit) | (s & ((1 << bit) - 1));
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<int> good(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        good[x] = true;
    }

    vector<vector<int>> dp(n + 1);
    dp[1] = {0, 1};

    for (int i = 2; i <= n; i++) {
        dp[i].assign(1 << i, (n - i) & 1);
        for (int s = 0; s < (1<<i); s++) {
            for (int j = 0; j < i; j++) {
                if (!good[j]) continue;
                if ((n - i) & 1) { // Bob
                    dp[i][s] &= dp[i - 1][remove(s, j)];
                } else { // Alice
                    dp[i][s] |= dp[i - 1][remove(s, j)];
                }
                // cout<<"s="<<s<<" j="<<j<<" res="<<remove(s,j)<<endl;
            }
        }
    }

    vector<int> cnt(n + 1);
    for (int s = 0; s < (1<<n); s++) {
        cnt[__builtin_popcount(s)] += dp[n][s];
    }
    // for(auto x:cnt){
    //     cout<<x<<" ";
    // }cout<<endl;

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += power(j - 1, n - i) * power(m - j + 1, i) % MOD * cnt[i] % MOD;
            if (ans >= MOD) {
                ans %= MOD;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
