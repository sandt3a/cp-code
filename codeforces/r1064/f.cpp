#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    auto work = [&]() -> int {
        vector<int> match(n, -1);
        vector<set<int>> ss(n * 2 + 1);

        for (int i = 0; i < n; i++) {
            ss[a[i]].insert(i);
        }

        int res = 0;
        for (int i = 0; i < n * 2; i++) {
            for (auto x: ss[i]) {
                auto &s = ss[i + 1];
                if (s.empty() || match[x] != -1) continue;
                auto it = s.lower_bound(x);
                if (i % 2 == 0) {
                    if (it == s.end()) {
                        continue;
                    }
                } else {
                    if (it == s.begin()) {
                        continue;
                    }
                    --it;
                }
                int y = *it;
                match[x] = y;
                match[y] = x;
                s.erase(it);
                res++;
            }
        }

        return res;
    };

    int ans = n;
    ans -= work();
    reverse(a.begin(), a.end());
    ans -= work();

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
