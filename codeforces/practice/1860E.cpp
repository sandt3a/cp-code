#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;

template<class T>
inline bool relax(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

inline int encode(int x, int y) {
    return (x - 'a') * 26 + y - 'a';
}

inline array<int, 2> decode(int x) {
    return {x / 26, x % 26};
}

void solve()
{
    string s;
    cin >> s;

    int n = static_cast<int>(s.length());

    constexpr int N = 26 * 26;
    // 26*26 super point
    // n normal point
    // np <-> np
    // np ->(cost 1)-> sp ->(cost 0)-> np
    // prepare dis_sp_sp ~ 3s
    // prepare dis_np_sp and dis_sp_np ~ bfs
    // dis_np_sp = dis_sp_np + 1
    // dis_np_np = abs(x - y)
    
    // array<array<int, N>, N> dss;
    // for (int i = 0; i < N; i++) {
    //     std::fill(dss.begin(), dss.end(), inf);
    //     dss[i][i] = 0;
    // }
    vector<vector<array<int, 2>>> e(n + N);

    for (int i = 0; i + 1 < n; i++) {
        int x = s[i];
        int y = s[i + 1];
        int cur = encode(x, y);
        if (i) {
            // int pre = encode(s[i - 1], x);
            // relax(dss[cur][pre], 2);
            e[i].push_back({i - 1, 1});
        }
        if (i + 2 < n) {
            // int suf = encode(y, s[i + 1]);
            // relax(dss[cur][suf], 2);
            e[i].push_back({i + 1, 1});
        }
        e[i].push_back({cur + n, 1});
        e[cur + n].push_back({i, 0});
    }

    array<vector<int>, N> dsn;

    auto bfs = [&](int st) {
        vector<int> dis(n + N, inf);
        deque<int> dq;
        dq.push_back(st);
        dis[st] = 0;
        while (!dq.empty()) {
            int x = dq.front();
            dq.pop_front();

            for (auto [y, w]: e[x]) {
                if (dis[y] > dis[x] + w) {
                    // if (dis[y] != inf) puts("error");
                    dis[y] = dis[x] + w;
                    if (w == 0) {
                        dq.push_front(y);
                    } else {
                        dq.push_back(y);
                    }
                }
            }
        }
        return dis;
    };

    for (int i = 0; i < N; i++) {
        dsn[i] = std::move(bfs(n + i));
        // cout<<"i:"<<i<<endl;
        // for (auto v: dsn[i]) {
        //     cout<<v<<" ";
        // }
        // cout<<endl;
    }

    int q;
    cin >> q;
    while (q--) {
        int st, ed;
        cin >> st >> ed;
        st--;
        ed--;
        int ans = abs(st - ed);
        for (int i = 0; i < N; i++) {
            int dns = dsn[i][st] + 1;
            relax(ans, dns + dsn[i][ed]);
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
