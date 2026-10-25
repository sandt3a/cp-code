#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b < 0 || a + b > n || (a + b > 0 && (a == 0 || b == 0))) {
        cout << "NO\n";
        return;
    }

    swap(a, b);
    int c = n - a - b;
    vector<int> X, Y;
    for (int i = 0; i < c; i++) {
        X.push_back(n - i);
        Y.push_back(n - i);
    }

    for (int i = 0; i < a; i++) {
        X.push_back(i + 1);
        Y.push_back(b + i + 1);
    }
    for (int i = 0; i < b; i++) {
        X.push_back(a + i + 1);
        Y.push_back(i + 1);
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << X[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << Y[i] << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
