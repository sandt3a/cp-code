#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using r64 = long double;

using numbers::pi;

struct Point {
    int x, y;

    friend istream& operator>>(istream &in, Point &p) {
        return in >> p.x >> p.y;
    };
};

i64 comb2(i64 n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}

void solve()
{
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    i64 ans = 0;

    for (int i = 0; i < n; i++) {
        Point base = p[i];
        vector<Point> vec = p;
        vec.erase(vec.begin() + i);

        auto ang = [&](Point a) -> r64 {
            return atan2l(a.y - base.y, a.x - base.x);
        };
        vector<r64> a;
        for (auto pp: vec) {
            a.push_back(ang(pp));
        }

        ranges::sort(a);
        r64 delta = 0;
        for (int j = 0, k = 0, step = 0; j < n - 1; j++, step--) {
            while (step < n - 1 && abs(a[k] + delta - a[j]) < pi) {
                k++;
                if (k >= n - 1) {
                    k -= n - 1;
                    delta = pi * 2;
                }
                step++;
                //cout<<"k="<<k<<"step="<<step<<endl;
            }
            int x = step - 1;
            int y = n - 2 - x;
            //cout<<"x="<<x<<" "<<"y="<<y<<endl;
            ans += comb2(x) * comb2(y);
        }
    }
    cout << ans / 2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
