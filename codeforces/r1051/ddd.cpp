#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MOD = 1e9 + 7;

template<class U, class V>
void add(U &x, V y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);  // a[1..n] 有效，a[0] 未使用
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // dp[i][v] 表示以第i个元素结尾的子序列中，状态为v的数量
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;  // 空序列

    for (int i = 0; i <= n; i++) {
        for (int v = 0; v <= n; v++) {
            if (dp[i][v] == 0) continue;  // 剪枝：没有这个状态就跳过
            
            for (int j = i + 1; j <= n; j++) {
                if (i == 0) {
                    // 从空序列添加j，形成以j为第一个元素的子序列
                    add(dp[j][a[j]], dp[i][v]);
                } else {
                    // 从i结尾的子序列添加j
                    if (v <= a[i]) {
                        add(dp[j][max(a[i], a[j])], dp[i][v]);
                    } else {
                        if (a[j] >= v) {
                            add(dp[j][a[j]], dp[i][v]);
                        } else if (a[j] >= a[i]) {
                            add(dp[j][v], dp[i][v]);
                        }
                    }
                }
            }
        }
    }

    i64 ans = 1;  // 空序列
    for (int i = 1; i <= n; i++) {
        for (int v = 1; v <= n; v++) {
            add(ans, dp[i][v]);
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
