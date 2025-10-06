#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int MOD = 676767677;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n); // left 0 + right 1
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    bool ok = true;

    vector<int> b(n, -1);
    auto ass = [&](int p, int v) {
        if (b[p] == 1 - v) {
            ok = false;
        } else {
            b[p] = v;
        }
    };

    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        if (d > 1 || d < -1) {
            ok = false;
        } else {
            if (d == 1) {
                ass(i, 0);
                ass(i - 1, 0);
            } else if (d == -1) {
                ass(i, 1);
                ass(i - 1, 1);
            } else {
                if (b[i - 1] != -1) {
                    ass(i, 1 - b[i-1]);
                }
            }
        }
    }

    if (!ok) {
        cout<<0<<"\n";
        return;
    }

    auto check = [&]() {
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            // assert(b[i]!=-1);
            pre[i+1] = pre[i] + b[i];
        }

        for (int i = 0; i < n; i++) {
            int x = i - pre[i] + pre[n] - pre[i+1];
            if (x != a[i]) {
                return false;
            }
        }
        return true;
    };

    auto push = [&]() {
        ok = true;
        for (int i = 1; i < n; i++) {
            int d = a[i] - a[i - 1];
            if (d > 1 || d < -1) {
                ok = false;
            } else {
                if (d == 1) {
                    ass(i, 0);
                    ass(i - 1, 0);
                } else if (d == -1) {
                    ass(i, 1);
                    ass(i - 1, 1);
                } else {
                    if (b[i - 1] != -1) {
                        ass(i, 1 - b[i-1]);
                    }
                }
            }
        }
        return ok;
    };

    int ans = 0;
    auto c = b;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (b[i]==-1) {
            flag = false;
            b[i] = 0;
            ans += push() && check();
            b = c;
            b[i] = 1;
            ans += push() && check();
            break;
        }
    }
    // cout<<"fflag="<<flag<<endl;
    if (flag) ans = check();
    cout << ans << endl;
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