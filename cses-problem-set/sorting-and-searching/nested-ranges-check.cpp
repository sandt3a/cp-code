#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct Fenwick {
    int n;
    vector<int> d;

    Fenwick(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        d.assign(n + 1, 0);
    }

    void add(int x, int v = 1) {
        //cout<<"[add] x="<<x<<" v="<<v<<endl;
        for (int i = x; i <= n; i += i & -i) {
            d[i] += v;
        }
    }

    int query(int x) {
        //cout<<"[query] x="<<x<<" n="<<n<<endl;
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            //cout<<"[query] i="<<i<<" n="<<n<<endl;
            res += d[i];
        }
        //cout<<"[query] res="<<res<<" n="<<n<<endl;
        return res;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    vector<int> ys;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        ys.push_back(y);
        ys.push_back(x);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto get = [&](int x) -> int {
        return (int)(lower_bound(ys.begin(), ys.end(), x) - ys.begin() + 1);
    };
    
    for (int i = 0; i < n; i++) {
        auto [x, y] = a[i];
        x = get(x);
        y = get(y);
        a[i] = {x, y};
    }

    vector<int> in(n);
    vector<int> ex(n);
    vector<int> ord(n);

    iota(ord.begin(), ord.end(), 0);

    Fenwick fw((int)ys.size());
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        if (a[x][0] != a[y][0]) {
            return a[x][0] < a[y][0];
        }
        return a[x][1] > a[y][1];
    });

    for (auto i: ord) {
        auto [l, r] = a[i];
        in[i] = fw.query((int)ys.size()) - fw.query(r - 1);
        fw.add(r);
    }

    fw.init((int)ys.size());
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        if (a[x][0] != a[y][0]) {
            return a[x][0] > a[y][0];
        }
        return a[x][1] < a[y][1];
    });

    for (auto i: ord) {
        auto [l, r] = a[i];
        ex[i] = fw.query(r);
        fw.add(r);
    }

    for (int i = 0; i < n; i++) {
        cout << !!ex[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << !!in[i] << " \n"[i == n - 1];
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
