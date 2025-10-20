#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

vector<vector<int>> d;

void init(int n = 2e5 + 1) {
    d.assign(n + 1, {});
    for (int i = 2; i <= n; i++) {
        // if (!is_prime[i]) continue;
        for (int j = i; j <= n; j += i) {
            d[j].push_back(i);
        }
        // cout<<"i="<<d[i].size()<<endl;
    }
    // cout<<"ok"<<endl;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // cout<<"?"<<endl;

    auto val = b;
    nth_element(val.begin(), val.begin() + 2, val.end());
    // cout<<"?"<<endl;

    int ans = val[0] + val[1]; // n >= 2
    multiset<int> ss;
    for (auto x: a) {
        for (auto y: d[x]) {
            if (ss.count(y)) {
                cout << "0\n";
                return;
            }
            ss.insert(y);
        }
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (auto y: d[x]) {
            ss.erase(ss.find(y));
        }
        for (auto y: d[x + 1]) {
            if (ss.count(y)) {
                ans = min(ans, b[i]);
            }
        }
        for (auto y: d[x]) {
            ss.insert(y);
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == min(val[0], val[1])) {
            for (auto x: ss) {
                if (a[i] % x == 0) continue;
                // cout<<"x="<<x<<" a="<<a[i]<<" b="<<b[i]<<endl;
                ans = min<i64>(ans, i64(x - a[i] % x) * b[i]);
            }
            break;
        }
    }

    cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
