#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int S = 21;

struct Trie {
    int tot;
    vector<array<int, 4>> a;

    Trie() {
        init();
    }

    void init() {
        tot = 0;
        a.assign(1, {0, 0, -1, -1});
    }

    int new_node(int idx) {
        ++tot;
        a.push_back({0, 0, -1, -1});
    }
    
    void insert(int x, int idx) {
        int cur = 0;
        for (int i = S - 1; i >= 0; i--) {
            auto node = a[cur];
            int d = x >> i & 1;
            if (!node[d]) {
                node[d] = new_node(idx);
            } else {
                node[d][3] = max(node[d][3], idx);
            }
        }
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        trie.insert(a[i], i);
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
