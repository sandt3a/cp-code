#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }

    if (*max_element(cnt, cnt + 26) > (n + 1) / 2) {
        cout << "-1\n";
        return;
    }

    string ans;
    int pre = -1;
    for (int i = 0; i < n; i++) {
        array<int, 26> ord, rk;
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int x, int y) {
            return cnt[x] > cnt[y];
        });
        for (int j = 0; j < 26; j++) {
            rk[ord[j]] = j;
        }
        for (int j = 0; j < 26; j++) {
            if (j == pre || cnt[j] == 0) {
                continue;
            }
            if (rk[j] && cnt[ord[0]] > (n - i) / 2) {
                continue;
            }
            cnt[j]--;
            ans += char(j + 'A');
            pre = j;
            break;
        }
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
