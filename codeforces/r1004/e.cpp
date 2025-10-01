#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    vector<int> a(n+1);
    vector<int> mn(n+1,INT_MAX);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            ans++;
        }
        mn[i] = min(mn[i-1], a[i]);
    }

    int mex = 1;
    map<int, int> cnt;
    int ok = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) {
            if (i == 1 || mn[i-1] >= mex) {
                ok = 1;
            }
        } else {
            cnt[a[i]]++;
            while (cnt[mex]) mex++;
            if (mn[i-1] < mex) {
                ok = 0;
            }
        }
    }
    cout << ans + ok << "\n";
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
