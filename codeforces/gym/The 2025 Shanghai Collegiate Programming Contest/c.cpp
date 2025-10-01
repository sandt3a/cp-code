#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m, bonus, l, r;
    cin >> n >> m >> bonus >> l >> r;

    vector<array<int, 4>> d(n);
    for (int i = 0; i < n; i++) {
        int s, a, b, c;
        cin >> s >> a >> b >> c;
        d[i] = {s, a, b, c};
    }

    auto work = [&]() -> i64 {
        i64 cnt = 0;
        i64 res = 0;
        
        for (int i = 0; i < n; i++) {
            auto [s, a, b, c] = d[i];

            if (a + c > 0) {
                res += a + c;
                cnt++;
            } else continue;
            i64 cc = min(max(a / b, 0), s - 1); // the max i s.t. a - b*i > 0;
            cnt += cc;
            res += i64(a) * cc - i64(b) * (1 + cc) * cc / 2;
        }

        if (l <= cnt && cnt <= r) {
            res += bonus;
        }
        if (cnt > m) {
            return 0;
        }
        // cout<<"cnt="<<cnt<<" res="<<res<<endl;

        return res;
    };

    auto solve = [&](int cnt) -> i64 {
        i64 res = 0;
        
        i64 L = -inf, R = inf;
        while (L <= R) {
            i64 M = (R-L) / 2 + L;

            i64 cc = 0;
            i64 rr = 0;
            
            for (int i = 0; i < n; i++) {
                auto [s, a, b, c] = d[i];

                if (a + c >= M) {
                    rr += a + c;
                    cc++;
                } else continue;
                i64 ccc = min<i64>(max<i64>((a-M) / b, 0), s - 1);
                cc += ccc;
                rr += i64(a) * ccc - i64(1 + ccc) * ccc / 2 * b;
            }

            if (cc >= cnt) {
                // cout<<"cc="<<cc<<" M="<<M<<endl;
                rr -= i64(cc - cnt) * M;

                // cout<<"rr="<<rr<<" cnt="<<cnt<<endl;
                if (l <= cnt && cnt <= r) {
                    rr += bonus;
                }
                res = rr;
                L = M + 1;
            } else {
                R = M - 1;
            }
        }

        // cout<<"cnt="<<cnt<<" res="<<res<<endl;
        return res;
    };

    i64 ans = work();
    for (auto x: {0, m, l, r}) {
        ans = max(ans, solve(x));
    }

    cout << ans << "\n";
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