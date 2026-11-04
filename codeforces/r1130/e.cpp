#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int INF = 0x3f3f3f3f;

void solve()
{
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;

    auto calc = [&]() {
        vector<int> q;
        for (int i = 1; i <= m; i++) {
            if (t[i] == 'W') {
                q.push_back(i);
            }
        }
        vector<int> gaps;
        for (int i = 0; i + 1 < (int)q.size(); i++) {
            gaps.push_back(q[i + 1] - q[i]);
        }
        sort(gaps.begin(), gaps.end());
        vector<i64> pre(q.size());
        for (int i = 0; i + 1 < (int)q.size(); i++) {
            pre[i + 1] = pre[i] + gaps[i];
        }
        int qm = q.size() ? q.back() : -INF;

        auto get = [&](int d) -> i64 {
            if (q.empty()) return 0;
            auto pos = upper_bound(gaps.begin(), gaps.end(), d + 1) - gaps.begin();
            i64 blank = pre.back() - pre[pos] - i64(gaps.size() - pos) * (d + 1);
            return q.back() - q.front() + d + 1 - blank;
        };

        int lastw = 0;
        vector<i64> ans;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'W') {
                lastw = i;
                continue;
            }

            if (lastw == 0) {
                ans.push_back(1 + get(i - 1));
            } else {
                ans.push_back(max(lastw + m, qm + i - 1) - lastw + 1);
            }
        }
        for (auto v: ans) {
            cout << v << " ";
        }
        cout << "\n";
    };

    calc();
    swap(n, m); swap(s, t);
    calc();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
