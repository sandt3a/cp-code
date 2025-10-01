#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[id[i]] = i;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << id[i] << " \n"[i == n - 1];
    // }

    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (id[i] == l) {
            l++;
        } else if (id[i] == r) {
            r--;
        } else {
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
