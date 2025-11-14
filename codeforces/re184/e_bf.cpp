#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<i64> x(n);
    vector<i64> y(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    i64 sumc = accumulate(c.begin(), c.end(), 0LL);

    i64 ans = sumc - *min_element(c.begin(), c.end());
    vector<i64> xs, ys;
    std::function<void(int, int, i64)> dfs = [&](int cur, int aim, i64 tot) {
        if (cur == aim) {
            i64 res = sumc - tot;
            res += 2 * (*max_element(xs.begin(), xs.end()) - *min_element(xs.begin(), xs.end()));
            res += 2 * (*max_element(ys.begin(), ys.end()) - *min_element(ys.begin(), ys.end()));
            ans = max(ans, res);
            // if (ans == res) {
            //     cout<<"res="<<res<<" tot="<<tot<<endl;
            //     for (auto x: xs) {
            //         cout<<x<<" ";
            //     }cout<<endl;
            //     for (auto y: ys) {
            //         cout<<y<<" ";
            //     }cout<<endl;
            // }
            return;
        }

        for (int i = 0; i < n; i++) {
            xs.push_back(x[i]);
            ys.push_back(y[i]);
            dfs(cur + 1, aim, tot + c[i]);
            xs.pop_back();
            ys.pop_back();
        }
    };

    for (int dep = 2; dep <= 4; dep++) {
        dfs(0, dep, 0);
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
