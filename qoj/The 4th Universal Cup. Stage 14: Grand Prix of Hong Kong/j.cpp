#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n;
    cin >> n;
    
    i64 lim[3];
    for (int i = 0; i < 3; i++) {
        cin >> lim[i];
    }

    i64 tot = 0;
    vector<int> pend[3];
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        p--;

        pend[p].push_back(c);
        tot += c;
    }

    i64 t;
    cin >> t;

    priority_queue<int> pq;

    i64 cur = tot, tt = 0;
    int enable[3] = {0};

    for (int i = 0; i < n; i++) {
        for (auto tty: {0, 1, 2}) {
            if (!enable[tty] && cur <= lim[tty]) {
                enable[tty] = 1;
                for (int co: pend[tty]) {
                    pq.push(co);
                }
                pend[tty].clear();
            }
        }

        if (pq.empty()) {
            cout << "NO\n";
            return;
        }
        int co = pq.top();
        pq.pop();
        tt += cur;
        cur -= co;
    }

    if (tt < t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
