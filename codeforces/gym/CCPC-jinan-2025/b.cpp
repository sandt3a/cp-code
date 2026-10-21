#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using State = array<int, 5>; // 2^6, n, n, n, n, (n - (a+b+c+d))

struct my_hash {
    const int base = 53;
    u64 operator() (const State &s) const {
        u64 res = 0;
        for (int i = 0; i < 5; i++) {
            res *= base;
            res += s[i];
        }
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<string> card(n);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    int tarot = 0;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        tarot |= x << i;
    }

    unordered_map<State, int, my_hash> dp;

    auto dfs = [&](this auto &&self, int t, int d, int c, int h, int s) -> int {
        if (d < 0 || c < 0 || h < 0 || s < 0) {
            return 0;
        }
        //cout<<"state=("<<t<<","<<d<<","<<c<<","<<h<<","<<s<<")"<<endl;
        State state {t, d, c, h, s};
        if (dp.count(state)) {
            return dp[state];
        }
        auto &res = dp[state];
        if (t == 0) {
            int a = n - d - c - h - s;
            assert(0 <= a && a <= 2);
            res = max(res, d / 5 + c / 5 + h / 5 + s / 5);
            if (a >= 1) {
                res = max(res, (d + 1) / 5 + c / 5 + h / 5 + s / 5);
                res = max(res, d / 5 + (c + 1) / 5 + h / 5 + s / 5);
                res = max(res, d / 5 + c / 5 + (h + 1) / 5 + s / 5);
                res = max(res, d / 5 + c / 5 + h / 5 + (s + 1) / 5);
            }
            if (a == 2) {
                res = max(res, (d + 2) / 5 + c / 5 + h / 5 + s / 5);
                res = max(res, d / 5 + (c + 2) / 5 + h / 5 + s / 5);
                res = max(res, d / 5 + c / 5 + (h + 2) / 5 + s / 5);
                res = max(res, d / 5 + c / 5 + h / 5 + (s + 2) / 5);
                res = max(res, (d + 1) / 5 + (c + 1) / 5 + (h + 0) / 5 + (s + 0) / 5);
                res = max(res, (d + 1) / 5 + (c + 0) / 5 + (h + 1) / 5 + (s + 0) / 5);
                res = max(res, (d + 1) / 5 + (c + 0) / 5 + (h + 0) / 5 + (s + 1) / 5);
                res = max(res, (d + 0) / 5 + (c + 1) / 5 + (h + 1) / 5 + (s + 0) / 5);
                res = max(res, (d + 0) / 5 + (c + 1) / 5 + (h + 0) / 5 + (s + 1) / 5);
                res = max(res, (d + 0) / 5 + (c + 0) / 5 + (h + 1) / 5 + (s + 1) / 5);
            }
            return res;
        }
        for (int i = 0; i < 6; i++) {
            if (t >> i & 1) {
                switch (i) {
                    case 0:
                        res = max(res, self(t ^ (1 << i), d, c, h, s));
                        res = max(res, self(t ^ (1 << i), d + 1, c - 1, h, s));
                        res = max(res, self(t ^ (1 << i), d + 1, c, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d + 1, c, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d + 2, c - 2, h, s));
                        res = max(res, self(t ^ (1 << i), d + 2, c, h - 2, s));
                        res = max(res, self(t ^ (1 << i), d + 2, c, h, s - 2));
                        res = max(res, self(t ^ (1 << i), d + 2, c - 1, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d + 2, c, h - 1, s - 1));
                        res = max(res, self(t ^ (1 << i), d + 2, c - 1, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d + 3, c - 3, h, s));
                        res = max(res, self(t ^ (1 << i), d + 3, c, h - 3, s));
                        res = max(res, self(t ^ (1 << i), d + 3, c, h, s - 3));
                        res = max(res, self(t ^ (1 << i), d + 3, c - 2, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d + 3, c - 2, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d + 3, c - 1, h - 2, s));
                        res = max(res, self(t ^ (1 << i), d + 3, c, h - 2, s - 1));
                        res = max(res, self(t ^ (1 << i), d + 3, c - 1, h, s - 2));
                        res = max(res, self(t ^ (1 << i), d + 3, c, h - 1, s - 2));
                        res = max(res, self(t ^ (1 << i), d + 3, c - 1, h - 1, s - 1));
                        break;
                    case 1: 
                        res = max(res, self(t ^ (1 << i), d, c, h, s));
                        res = max(res, self(t ^ (1 << i), d - 1, c + 1, h, s));
                        res = max(res, self(t ^ (1 << i), d, c + 1, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d, c + 1, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 2, c + 2, h, s));
                        res = max(res, self(t ^ (1 << i), d, c + 2, h - 2, s));
                        res = max(res, self(t ^ (1 << i), d, c + 2, h, s - 2));
                        res = max(res, self(t ^ (1 << i), d - 1, c + 2, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d, c + 2, h - 1, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 1, c + 2, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 3, c + 3, h, s));
                        res = max(res, self(t ^ (1 << i), d, c + 3, h - 3, s));
                        res = max(res, self(t ^ (1 << i), d, c + 3, h, s - 3));
                        res = max(res, self(t ^ (1 << i), d - 2, c + 3, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d - 2, c + 3, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 1, c + 3, h - 2, s));
                        res = max(res, self(t ^ (1 << i), d, c + 3, h - 2, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 1, c + 3, h, s - 2));
                        res = max(res, self(t ^ (1 << i), d, c + 3, h - 1, s - 2));
                        res = max(res, self(t ^ (1 << i), d - 1, c + 3, h - 1, s - 1));
                        break;
                    case 2:
                        res = max(res, self(t ^ (1 << i), d, c, h, s));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h + 1, s));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h + 1, s));
                        res = max(res, self(t ^ (1 << i), d, c, h + 1, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 2, c, h + 2, s));
                        res = max(res, self(t ^ (1 << i), d, c - 2, h + 2, s));
                        res = max(res, self(t ^ (1 << i), d, c, h + 2, s - 2));
                        res = max(res, self(t ^ (1 << i), d - 1, c - 1, h + 2, s));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h + 2, s - 1));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h + 2, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 3, c, h + 3, s));
                        res = max(res, self(t ^ (1 << i), d, c - 3, h + 3, s));
                        res = max(res, self(t ^ (1 << i), d, c, h + 3, s - 3));
                        res = max(res, self(t ^ (1 << i), d - 2, c - 1, h + 3, s));
                        res = max(res, self(t ^ (1 << i), d - 2, c, h + 3, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 1, c - 2, h + 3, s));
                        res = max(res, self(t ^ (1 << i), d, c - 2, h + 3, s - 1));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h + 3, s - 2));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h + 3, s - 2));
                        res = max(res, self(t ^ (1 << i), d - 1, c - 1, h + 3, s - 1));
                        break;
                    case 3:
                        res = max(res, self(t ^ (1 << i), d, c, h, s));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h, s + 1));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h, s + 1));
                        res = max(res, self(t ^ (1 << i), d, c, h - 1, s + 1));
                        res = max(res, self(t ^ (1 << i), d - 2, c, h, s + 2));
                        res = max(res, self(t ^ (1 << i), d, c - 2, h, s + 2));
                        res = max(res, self(t ^ (1 << i), d, c, h - 2, s + 2));
                        res = max(res, self(t ^ (1 << i), d - 1, c - 1, h, s + 2));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h - 1, s + 2));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h - 1, s + 2));
                        res = max(res, self(t ^ (1 << i), d - 3, c, h, s + 3));
                        res = max(res, self(t ^ (1 << i), d, c - 3, h, s + 3));
                        res = max(res, self(t ^ (1 << i), d, c, h - 3, s + 3));
                        res = max(res, self(t ^ (1 << i), d - 2, c - 1, h, s + 3));
                        res = max(res, self(t ^ (1 << i), d - 2, c, h - 1, s + 3));
                        res = max(res, self(t ^ (1 << i), d - 1, c - 2, h, s + 3));
                        res = max(res, self(t ^ (1 << i), d, c - 2, h - 1, s + 3));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h - 2, s + 3));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h - 2, s + 3));
                        res = max(res, self(t ^ (1 << i), d - 1, c - 1, h - 1, s + 3));
                        break;
                    case 4:
                        res = max(res, self(t ^ (1 << i), d - 1, c, h, s));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h, s));
                        res = max(res, self(t ^ (1 << i), d, c, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d, c, h, s - 1));
                        break;
                    case 5:
                        if (int a = n - d - c - h - s; a > 0) {
                            res = max(res, self(t ^ (1 << i), d - 1, c, h, s));
                            res = max(res, self(t ^ (1 << i), d, c - 1, h, s));
                            res = max(res, self(t ^ (1 << i), d, c, h - 1, s));
                            res = max(res, self(t ^ (1 << i), d, c, h, s - 1));
                            break;
                        }
                        res = max(res, self(t ^ (1 << i), d - 1, c + 1, h, s));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h + 1, s));
                        res = max(res, self(t ^ (1 << i), d - 1, c, h, s + 1));
                        res = max(res, self(t ^ (1 << i), d + 1, c - 1, h, s));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h + 1, s));
                        res = max(res, self(t ^ (1 << i), d, c - 1, h, s + 1));
                        res = max(res, self(t ^ (1 << i), d + 1, c, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d, c + 1, h - 1, s));
                        res = max(res, self(t ^ (1 << i), d, c, h - 1, s + 1));
                        res = max(res, self(t ^ (1 << i), d + 1, c, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d, c + 1, h, s - 1));
                        res = max(res, self(t ^ (1 << i), d, c, h + 1, s - 1));
                        break;
                    default: assert(false);
                }
            }
        }
        return res;
    };

    int d = 0, c = 0, h = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (card[i][1] == 'D') d++;
        if (card[i][1] == 'C') c++;
        if (card[i][1] == 'H') h++;
        if (card[i][1] == 'S') s++;
    }
    int ans = dfs(tarot, d, c, h, s);
    
    cout << ans << endl;
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
