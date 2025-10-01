#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.length();
    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            ans = 1;
            break;
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

