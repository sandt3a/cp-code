#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int inf = 0x3f3f3f3f;

void solve()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> a0(n + 1), b0(n + 1);
    for (int i = 0; i < n; i++) {
        a0[i + 1] = a0[i] + (a[i] == '0');
    }
    for (int i = 0; i < n; i++) {
        b0[i + 1] = b0[i] + (b[i] == '0');
    }

    vector<array<int, 3>> vec;
    for (int i = 1; i <= n; i++) {
        int x = b0[i];
        int y = i - x;
        int d = x - y;
        vec.push_back({d, x, y});
    }

    sort(vec.begin(), vec.end());

    vector<i64> prex(n + 1);
    vector<i64> prey(n + 1);
    for (int i = 0; i < n; i++) {
        prex[i + 1] = prex[i] + vec[i][1];
        prey[i + 1] = prey[i] + vec[i][2];
    }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = a0[i];
        int kk = i - 2 * k;

        int pos = upper_bound(vec.begin(), vec.end(), (array<int, 3>){kk, inf, inf}) - vec.begin();
        i64 res = 1ll * (n - pos) * (i - k) + 1ll * pos * k + prex[pos] - prey[pos] + prey[n];
        ans += res;
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
