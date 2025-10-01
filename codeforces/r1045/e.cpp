#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;

    std::vector<int> a(n + 1), ans(n + 1);

    auto work = [&](int p) -> int {
        int x = p;
        int cnt = 0;
        while (x <= n) {
            x += a[x];
            cnt++;
        }
        return cnt;
    };

    auto calc = [&](int p) {
        int t = work(p + 2);
        int s = work(p + 3);

        int pos;
        if (s == t) {
            pos = p;
        } else {
            pos = p + 1;
        }

        cout << "throw " << pos << endl;
        int res;
        cin >> res;

        if (pos == p) {
            if (res == t + 2) {
                a[p] = 1;
            } else {
                a[p] = 2;
            }
        } else {
            if (res == t + 1) {
                a[p + 1] = 1;
            } else {
                a[p + 1] = 2;
            }
        }
        
        cout << "swap " << p << endl;
        swap(a[p], a[p + 1]);

        cout << "throw " << pos << endl;
        cin >> res;

        if (pos == p) {
            if (res == t + 2) {
                a[p] = 1;
            } else {
                a[p] = 2;
            }
        } else {
            if (res == t + 1) {
                a[p + 1] = 1;
            } else {
                a[p + 1] = 2;
            }
        }

        ans[p] = a[p + 1];
        ans[p + 1] = a[p];
    };

    for (int i = n; i > 1; i -= 2) {
        calc(i - 1);
    }

    if (n & 1) {
        int t = work(2);
        int s = work(3);
        if (t != s) {
            cout << "throw " << 1 << endl;
            int res;
            cin >> res;
            if (res == t + 1) {
                ans[1] = 1;
            } else {
                ans[1] = 2;
            }
        } else {
            cout << "swap " << 1 << endl;
            t = work(3);
            s = work(4);
            assert(s != t);
            cout << "throw " << 2 << endl;
            int res;
            cin >> res;
            if (res == t + 1) {
                ans[1] = 1;
            } else {
                ans[1] = 2;
            }
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    cout.flush();
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
