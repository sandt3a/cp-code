#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 g = 0;
    for (int i = 0; i < n; i++) {
        g = std::gcd(g, a[i]);
    }
    if (g == 1) {
        for (int i = 0; i < n; i++) {
            i64 t = a[i] % (k + 1);
            if (t != 0) {
                a[i] += t * k;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
