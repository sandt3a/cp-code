#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int S = 24;
constexpr int FULL = (1 << S) - 1;

void solve()
{
    int n;
    cin >> n;
    
    vector<int> cnt(1 << S);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int mask = 0;
        for (auto c: str) {
            mask |= 1 << (c - 'a');
        }
        cnt[mask]++;
    }

    auto dp = cnt;
    for (int i = 0; i < S; i++) {
        for (int s = 0; s < (1 << S); s++) {
            if (s >> i & 1) {
                dp[s] += dp[s ^ (1 << i)];
            }
        }
    }

    i64 ans = 0;
    for (int x = 0; x < (1 << S); x++) {
        i64 v = n - dp[x];
        ans ^= v * v;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
