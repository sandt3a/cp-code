#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    string s;
    cin >> s;

    int n = (int)s.length();

    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }

    int flag = 0, core = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            flag++;
            core = i;
        }
    }

    if (flag > 1) {
        cout << "NO SOLUTION" << "\n";
        return;
    }

    string ans;
    for (int i = 0; i < 26; i++) {
        cnt[i] /= 2;
        ans += string(cnt[i], 'A' + i);
    }
    cout << ans;
    if (flag) {
        cout << char(core + 'A');
    }
    reverse(ans.begin(), ans.end());
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
