#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;

using i64 = long long;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    oset<int> ss;
    ss.insert(b[0]);
    for (int i = 1; i < n; i++) {
        ss.insert(b[i]);
        int x = b[i];
        int y = b[i - 1];
        if (x < y) {
            swap(x, y);
        }
        if (ss.order_of_key(x) - ss.order_of_key(y) > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

    // oset<pair<int, int>> ss;
    // ss.insert({b[0], 0});

    // for (int i = 1; i < n; i++) {
    //    // if (b[i] > b[i - 1]) {
    //         ss.insert({b[i], i * 2 - 1});
    //         ss.insert({b[i], i * 2});
    //         if (ss.find_by_order(i)->first != b[i]) {
    //             cout << "NO\n";
    //             return;
    //         }
    //    // }
    // }
    // cout << "YES\n";
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
