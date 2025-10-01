#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto f = [&](int x) {
        return min(x % k, k - x % k);
    };

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[f(a[i])]++;
        mp[f(b[i])]--;
    }
    
    for (auto [key, val]: mp) {
        if (val != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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