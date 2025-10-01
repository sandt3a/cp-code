#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

int query(int st, const vector<int> &ss) {
    cout << "? " << st + 1 << " " << ss.size();
    for (auto x: ss) {
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

    vector<int> idx;
    for (int i = 0; i < n; i++) {
        idx.push_back(i);
    }

    vector<int> dis(n);
    for (int i = 0; i < n; i++) {
        dis[i] = query(i, idx);
    }

    auto id = idx;
    sort(id.begin(), id.end(), [&](int x, int y) {
        return dis[x] > dis[y];
    });

    int st = id[0];
    vector<int> path = {st};
    auto vec = idx;
    for (int d = dis[st] - 1; d >= 1; d--) {
        vector<int> pending;
        for (auto i: id) {
            if (dis[i] == d) {
                pending.push_back(i);
            }
        }

        bool flag = false;
        
        for (auto i: pending) {
            vec.erase(lower_bound(vec.begin(), vec.end(), i));
            if (!flag && query(st, vec) < dis[st]) {
                path.push_back(i);
                flag = true;
            }
        }

        vec.insert(lower_bound(vec.begin(), vec.end(), path.back()), path.back());

        assert(flag);
    }

    cout << "! " << dis[st];
    for (auto x: path) {
        cout << " " << x + 1;
    }
    cout << endl;
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
