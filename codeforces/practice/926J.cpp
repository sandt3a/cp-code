#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve()
{
    int n;
    cin >> n;

    set<pair<int, int>> ss;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        int nl = l, nr = r;

        auto itl = ss.upper_bound({l, 1000000000});
        if (itl != ss.begin()) {
            itl = std::prev(itl);
        }
        auto itr = ss.upper_bound({r, 1000000000});

        for (auto it = itl; it != itr; it++) {
            // cout<<" it: l="<<it->first<<" r="<<it->second<<endl;
            if (it->second < l) {
                itl++;
                continue;
            }
            if (it->first <= r || it->second >= l) {
                nl = min(nl, it->first);
                nr = max(nr, it->second);
            }
        }
        ss.erase(itl, itr);
        ss.insert({nl, nr});
        // cout<<"set:";
        // for (auto [l,r]: ss) {
        //     cout<<"l="<<l<<" r="<<r<<endl;
        // }cout<<endl;
        cout << ss.size() << " \n"[i == n - 1];
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