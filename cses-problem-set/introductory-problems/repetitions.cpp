#include <bits/stdc++.h>
using namespace std;

string s;

void input()
{
    cin >> s;
}

void solve()
{
    int n = s.length();
    int st = -1, rep = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (st == -1 || st != s[i]) {
            st = s[i];
            rep = 1;
        } else {
            rep++;
        }
        ans = max(ans, rep);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
    return 0;
}
