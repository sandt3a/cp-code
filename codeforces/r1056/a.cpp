#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    int win = n, lose = 0;
    while (win > 1 || lose > 1) {
        // cout<<win<<" "<<lose<<endl;
        ans += win / 2 + lose / 2;
        lose = lose - lose / 2 + win / 2;
        win = win - win / 2;
    }
    cout << ans + 1 << endl;
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
