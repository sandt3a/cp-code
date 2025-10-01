#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

vector<int> factor(i64 n) {
    vector<int> s;
    while (n) {
        s.push_back((int)n%10);
        n/=10;
    }
    return s;
}

bool check(i64 n) {
    auto d = factor(n);
    for (auto x: d)
        if (x == 7)
            return true;
    return false;
}

void solve()
{
    i64 n;
    cin >> n;
    i64 delta = 9;
    int ans = 100;
    for (int i = 1; i <= 9; i++) {
        for (int t = 0; t <= 10; t++) {
            if (check(n + t*delta)) {
                ans = min(ans, t);
            }
        }
        delta = delta * 10 + 9;
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



