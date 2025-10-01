#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    cout << (n % 4 ? "Alice" : "Bob") << "\n";
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
