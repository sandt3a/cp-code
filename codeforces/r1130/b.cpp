#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int cnt = 0;
    for (auto c: a) {
        cnt += c == 'f';
    }
    for (auto c: b) {
        cnt += c == 'f';
    }
    cout << cnt % 2 << "\n";
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
