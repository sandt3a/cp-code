#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> mark(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mark[x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            cout << i << endl;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

