#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    i64 n;
    cin >> n;
    
    i64 sum = (n + 1) * n / 2;
    if (sum % 2 == 1) {
        cout << "NO\n";
        return;
    }

    vector<int> pa, pb;
    if (n % 4 == 0) {
        for (int i = 1; i < n - i; i += 2) {
            pa.push_back(i);
            pa.push_back(n - i + 1);
            pb.push_back(i + 1);
            pb.push_back(n - i);
        }
    } else {
        pa = {1, 2};
        pb = {3};
        for (int i = 4; i < n - i + 3; i += 2) {
            pa.push_back(i);
            pa.push_back(n - i + 4);
            pb.push_back(i + 1);
            pb.push_back(n - i + 3);
        }
    }
    cout << "YES\n";
    cout << pa.size() << "\n";
    for (auto x: pa) {
        cout << x << " \n"[x == pa.back()];
    }
    cout << pb.size() << "\n";
    for (auto x: pb) {
        cout << x << " \n"[x == pb.back()];
    }
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
