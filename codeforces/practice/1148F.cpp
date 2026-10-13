#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int S = 62;

int fls(u64 x) {
    return x ? 64 - __builtin_clzll(x) : 0;
}

void solve()
{
    int n;
    cin >> n;

    vector<i64> val(n), mask(n);
    vector<vector<int>> mili(S);
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> mask[i];

        mili[fls(mask[i]) - 1].push_back(i);
    }

    i64 sum = accumulate(val.begin(), val.end(), 0LL);

    i64 cur_mask = 0;
    for (int b = 0; b < S; b++) {
        i64 s = 0;
        for (auto i: mili[b]) {
            if (__builtin_parityll(mask[i] & cur_mask) == 0) {
                s += val[i];
            } else {
                s -= val[i];
            }
        }
        if (s && (s > 0) == (sum > 0)) {
            cur_mask ^= 1LL << b;
        }
    }

    cout << cur_mask << endl;
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
