#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    for (int d = 1; ; d++) {
        for (int i = 0; i < n; i++) {
            int j = (i + d) % n;

            cout << i+1 << " " << j+1 << endl;

            int res;
            cin >> res;
            if (res == 1) {
                return;
            }
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