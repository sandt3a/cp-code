#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

vector<int> get(int n) {
    vector<int> res;
    while (n) {
        res.push_back(n & 1);
        n >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;

    auto bits = get(n);

    int c = __builtin_ctz(n);
    for (int i = 0; i < c; i++) {
        bits.push_back(0);
    }
    auto b = bits;
    reverse(b.begin(), b.end());
    int m = (int)bits.size();

    if (b != bits || (m % 2 == 1 && bits[m / 2] == 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
