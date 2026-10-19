#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string s;
    cin >> s;

    vector<int> lens, st;
    for (int i = 0, len = 0; i < n; i++) {
        if (s[i] == '0') {
            if (len == 0) {
                st.push_back(i);
            }
            len++;
        }
        if (s[i] == '1' || i == n - 1) {
            if (len) {
                lens.push_back(len);
            }
            len = 0;
        }
    }

    int m = static_cast<int>(lens.size());
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return lens[x] < lens[y];
    });

    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += lens[i] / b;
    }

    vector<int> ans;
    for (int i: ord) {
        for (int j = b - 1; j < lens[i]; j += b) {
            ans.push_back(st[i] + j);
            sum--;
            if (sum < a) goto end;
        }
    }

end:
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x + 1 << " \n"[x == ans.back()];
    }
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
