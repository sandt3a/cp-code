#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string t = s;
    sort(t.begin(), t.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cnt++;
        }
    }
    cout << (cnt+1) / 2 << endl;
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
