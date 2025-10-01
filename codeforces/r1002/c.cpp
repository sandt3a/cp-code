#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> suf(n, 0);
    multiset<int> ss;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= 0; j--) {
            if (a[i][j] != 1) break;
            suf[i]++;
        }
        ss.insert(suf[i]);
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        auto it = ss.lower_bound(i);
        if (it != ss.end()) {
            ans++;
            ss.erase(it);
        } else break;
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

