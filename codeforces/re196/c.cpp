#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    int A = 0, B = 0;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        A |= i;
        B ^= i;
        c[i] = i ^ (i<<1);
    }

    int C = B;
    vector<int> ans(n + 1);
    int b = std::__lg(n) + 1;
    //cout<<"b="<<b<<" n="<<n<<endl;
    ans[n] = 1;
    B ^= c[n];
    for (int i = b; i >= 1; i--) {
        if ((B >> i & 1) == 0) {
            ans[1 << (i - 1)] = 1;
            B ^= c[1<<(i-1)];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i]) C ^= c[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    //cout<<" C="<<C<<" B="<<B<<" A="<<A<<endl;
    assert(C >= 2 * A);
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
