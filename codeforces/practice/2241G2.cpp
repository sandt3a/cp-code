#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void print(i128 x) {
    vector<int> stk;
    do {
        stk.push_back((int)(x % 10));
        x /= 10;
    } while (x);
    reverse(stk.begin(), stk.end());
    for (auto x: stk) {
        cout << x;
    }
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> nxt(n, n);

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] % a[stk.back()] != 0) {
            nxt[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    while (!stk.empty()) {
        nxt[stk.back()] = n;
        stk.pop_back();
    }

    i128 ans = 0;
    for (int l = 0; l < n; l++) {
        int g = a[l];
        int res = 0;
        for (int r = l + 1; r < n; r = nxt[r]) {
            res = max(res, min(g - a[r] % g, a[r] % g));
            // cout << "l="<<l<<" r="<<r<<" res="<<min(g - a[r] % g, a[r] % g)<<endl;
            if (res > 0 || g == 1) {
                ans += 1ll * res * (n - r);
                break;
            }
            g = std::gcd(g, a[r]);
        }
    }

    print(ans);
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
