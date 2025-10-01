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

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    auto work = [&](vector<int> vec) -> i64 {
        if (vec.empty()) return 0LL;
        // sort(vec.begin(), vec.end());

        int m = (int)vec.size();
        int mid = vec[m / 2];

        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + (s[i] != s[vec[0]]);
        }

        i64 res = 0;
        for (int i = 0; i < m; i++) {
            // cout<<"mid="<<mid<<" v="<<vec[i]<<endl;
            res += abs(pre[mid] - pre[vec[i]]);
        }
        return res;
    };

    i64 ans = min(work(a), work(b));

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
