#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;

    vector<int> up(n);
    for (int i = 0; i < n; i++) {
        cin >> up[i];
    }
    vector<int> down(n);
    for (int i = 0; i < n; i++) {
        cin >> down[i];
    }

    const int L = 2 * n + 1;
    vector<vector<int>> vup(L), vdown(L);
    for (int i = 0; i < n; i++) {
        vup[up[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        vdown[down[i]].push_back(i);
    }

    auto mark = [&](const vector<int> &id, set<int> &b) {
        for (auto i: id) {
            b.erase(i);
        }
    };
    auto remark = [&](const vector<int> &id, set<int> &b) {
        for (auto i: id) {
            b.insert(i);
        }
    };

    set<int> badu, badd;
    for (int i = 0; i < n; i++) {
        badu.insert(i);
        badd.insert(i);
    }
    auto check = [&]() -> bool {
        if (badu.count(0) || badd.count(n - 1)) {
            return false;
        }
        if (badu.empty() || badd.empty()) {
            return true;
        }
        return *badu.begin() - 1 >= *badd.rbegin() + 1;
    };

    auto print = [&](set<int> s) {
        for (auto x: s) {
            cout<<x<<" ";
        }
        cout<<endl;
    };

    i64 ans = 0;
    for (int i = 1, j = 0; i < L; i++) {
        while (j + 1 < L && !check()) {
            j++;
            mark(vup[j], badu);
            mark(vdown[j], badd);
        }
        if (!check()) {
            break;
        }
        //print(badu);
        //print(badd);
        //cout<<"i="<<i<<" j="<<j<<endl;
        ans += (L - j);
        remark(vup[i], badu);
        remark(vdown[i], badd);
    }

    cout << ans << endl;
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
