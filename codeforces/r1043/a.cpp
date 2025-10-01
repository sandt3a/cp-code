#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    string a, b, c;
    int n, m;
    cin >> n >> a >> m >> b >> c;

    // cout<<n<<" "<<m<<" "<<a<<" "<<b<<" "<<c<<endl;

    deque<char> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        if (c[i] == 'D') {
            dq.push_back(b[i]);
        } else {
            dq.push_front(b[i]);
        }
    }
    for (auto x: dq) {
        cout<<x;
    }
    cout<<"\n";
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
