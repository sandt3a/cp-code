#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int l, r;
	cin >> l >> r;
	cout << r - l + (l==1&&r==1) << "\n";
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
