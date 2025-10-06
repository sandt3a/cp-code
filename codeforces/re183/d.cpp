#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

i64 power(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    // k = 1 no
    // k >= n - 1
    // n-1 n 1 2 3 .. n-2
    // 1 * (n - 1)
    // 1 n-1 n 2 3 .. n-2
    // 2 * (n-2)

    // a b c
    // (b+c)+1..(a+b+c) c+1..{b+c} 1..c
    // a * b + a * c + b * c

    // \sum a[i] * a[j] (i<j) == k
    // \sum a[i] == n

    auto check = [&](vector<int> a) {
        int res = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l+1; r <= n; r++) {
                res += !is_sorted(a.begin() + l, a.begin() + r);
            }
        }
        // cout<<"res="<<res<<endl;
        return res == k;
    };

    for (int len = 1; len <= n; len++) {
        vector<int> a;
        std::function<bool(int, int, int)> dfs = [&](int cur, int s, int sp) {
            if (cur == len) {
                return s == n && sp == k;
            }

            auto eval = [&]() {
                int res = 0;
                int q = (n - s) / (len - cur);
                int r = (n - s) % (len - cur);
                int ss = s;
                for (int i = 0; i < len - cur; i++) {
                    if (i < r) {
                        res += ss * (q + 1);
                        ss += q + 1;
                    } else {
                        res += ss * q;
                        ss += q;
                    }
                }
                return res;
            };

            if (n - s < len - cur || sp + (n - s) * s > k || sp + eval() < k) {
                return false;
            }
            
            for (int i = (cur == len - 1 ? n - s : 1); i + s <= n; i++) {
                a.push_back(i);
                if (dfs(cur + 1, s + i, sp + i * s)) {
                    return true;
                }
                a.pop_back();
            }
            return false;
        };

        if (dfs(0, 0, 0)) {
            // for (auto x: a) {
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            vector<int> b(n);
            int p = 0, s = 0;
            for (auto x: a) {
                int cur = n - s - x;
                for (int i = 0; i < x; i++) {
                    b[p++] = cur++;
                }
                s += x;
            }
            for (int i = 0; i < n; i++) {
                cout << b[i] + 1 << " \n"[i == n - 1];
            }
            // cout.flush();
            // assert(check(b));
            return;
        }
    }
    cout << "0\n";
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
