#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        int x = std::min(a[i], a[i+1]);
        a[i] -= x;
        a[i+1] -= x;
    }
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


