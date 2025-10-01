#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    multiset<int> ss;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        auto it = ss.upper_bound(r);
        if (it != ss.end()) {
            ss.erase(it);
        }
        ss.insert(l);
        cout << ss.size() << " \n"[i == n - 1];
    }
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
