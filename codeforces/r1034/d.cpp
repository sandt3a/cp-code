#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (count(s.begin(), s.end(), '1') <= k) {
        cout << "Alice\n";
        return;
    }

    if (k * 2 > n) {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
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
