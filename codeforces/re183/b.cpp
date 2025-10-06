#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    if (m == n) {
        for (int i = 0; i < n; i++) {
            s[i] = '-';
        }
        cout << s << endl;
        return;
    }

    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    int c = count(s.begin(), s.end(), '2');

    s.assign(n, '+');
    for (int i = 0; i < a + c; i++) {
        s[i] = i >= a ? '?' : '-';
    }
    for (int i = 0; i < b + c; i++) {
        s[n - 1 - i] = i >= b ? '?' : '-';
    }
    cout << s << endl;
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
