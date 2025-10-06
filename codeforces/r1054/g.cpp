#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

std::mt19937 rng(std::random_device{}());

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = make_pair(a[i], i);
    }
    sort(vec.begin(), vec.end());

    auto get = [&](int l, int r, int x) {
        return lower_bound(vec.begin(), vec.end(), make_pair(x, r))
             - lower_bound(vec.begin(), vec.end(), make_pair(x, l));
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        vector<int> ans;
        std::uniform_int_distribution<> randint(l, r - 1);
        for (int _ = 0; _ < 50; _++) {
            int p = randint(rng);
            int x = a[p];
            if (get(l, r, x) > (r - l) / 3) {
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        if (ans.empty()) {
            ans.push_back(-1);
        }

        for (auto x: ans) {
            cout << x << " \n"[x == ans.back()];
        }
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
