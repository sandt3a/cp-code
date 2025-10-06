#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MOD = 676767677;

void solve()
{
    int n;
    cin >> n;

    std::function<bool(int, int)> solve = [&](int l, int r) -> bool {
        if (l == r) return false;
        if (l + 1 == r) return false;

        int m = (l + r) / 2;
        if(solve(l, m)) return true;
        if(solve(m, r)) return true;
        for (int i = l; i < m; i++) {
            for(int j = m; j < r; j++) {
                cout << i + 1 << " " << j + 1 << endl;
                int res;
                cin >> res;
                if (res == 1) {
                    return true;
                }
            }
        }
        return false;
    };

    solve(0, n);
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