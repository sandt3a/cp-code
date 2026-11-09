#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "0\n";
        return;
    }

    if (gcd(a, b) == 1) {
        cout << "1\n";
        cout << b - a << "\n";
        return;
    }

    auto it = lower_bound(primes.begin(), primes.end(), a);
    while (gcd(*it, b) != 1) {
        it++;
    }

    if (*it < b) {
        cout << "2\n";
        cout << *it - a << " " << b - *it << "\n";
        return;
    }

    assert(b - a <= 300);

    queue<int> q;
    q.push(a);

    vector<int> vis(b + 1);
    vector<int> from(b + 1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y = x + 1; y <= b; y++) {
            if (gcd(x, y) == 1) {
                if (!vis[y]) {
                    vis[y] = 1;
                    from[y] = x;
                    q.push(y);
                }
            }
        }
    }

    assert(vis[b]);
    vector<int> ans;
    for (int z = b; z != a; z = from[z]) {
        ans.push_back(z - from[z]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(200000);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
