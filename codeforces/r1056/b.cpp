#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    if (k == n * n - 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            a[i].assign(n, 'R');
            a[i][n - 1] = 'L';
        }

        for (int i = 0; i < k / n; i++) {
            a[i].assign(n, 'L');
        }
        for (int i = k / n, j = 0; j < k % n; j++) {
            a[i][j] = 'L';
        }
        if (k % n == n - 1) {
            a[k / n].back() = 'D';
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << "\n";
        }
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
