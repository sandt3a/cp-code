#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int query(int x, int y) {
    int res;
    cout << "? " << x+1 << " " << y+1 << endl;
    cin >> res;
    return res;
}

void answer(int x) {
    cout << "! " << "AB"[x] << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

