#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using r64 = long double;
using i128 = __int128;

int query(vector<int> a) {
    cout << "? " << a.size();
    for (auto x: a) {
        cout << " " << x + 1;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n * 2);
    vector<int> vec = {0};
    vector<int> all;

    for (int i = 1; i < n * 2; i++) {
        vec.push_back(i);
        int mad = query(vec);
        if (mad == 0) {
            continue;
        }
        a[i] = mad;
        all.push_back(i);
        vec.pop_back();
    }

    //assert(all.size() == n);
    for (int i = 0; i < n * 2; i++) {
        if (a[i] == 0) {
            all.push_back(i);
            a[i] = query(all);
            all.pop_back();
        }
    }

    cout << "!";
    for (int i = 0; i < 2 * n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
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
