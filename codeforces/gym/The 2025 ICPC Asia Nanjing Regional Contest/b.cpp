#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

const r64 pi = acos(-1.0);
const r64 eps = 1e-12;

struct Point {
    int x = 0;
    int y = 0;
    r64 a;

    r64 ang() const {
        return atan2l(y, x);
    }

    bool operator<(const Point &rhs) const {
        return a < rhs.a;
    }

};
ostream& operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

i64 dot(const Point &a, const Point &b) {
    return i64(a.x) * b.x + i64(a.y) * b.y;
}
i64 det(const Point &a, const Point &b) {
    return i64(a.x) * b.y - i64(b.x) * a.y;
}

void solve()
{
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0) {
            i--;
            n--;
            continue;
        }
        p[i] = {a, b, atan2l(b, a)};
    }

    p.resize(n);
    sort(p.begin(), p.end());
    p.resize(n << 1);
    for (int i = 0; i < n; i++) {
        p[i + n] = p[i];
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        j = max(j, i + 1);
        while (j < i + n && (det(p[i], p[j]) > 0 || (det(p[i], p[j]) == 0 && dot(p[i], p[j]) > 0))) {
            j++;
        }
        ans = max(ans, j - i);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
