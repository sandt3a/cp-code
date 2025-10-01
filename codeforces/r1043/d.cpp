#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

std::vector<i64> len, sum, pw;

void init(int n = 16) {
    len.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    pw.assign(n + 1, 0);

    pw[0] = 1;
    len[0] = 1;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 10;
        len[i] = i * (pw[i] - pw[i - 1]) + len[i - 1];
        sum[i] = sum[i - 1];
        for (int x = 1; x <= 9; x++) {
            sum[i] += pw[i - 1] * x + sum[i - 1];
        }
        // cout << pw[i] << " " << len[i] << " " << sum[i] << endl;
    }

    len[0] = 0;
}

void solve()
{
    i64 n;
    cin >> n;
    n++;

    int B = 0;
    while (len[B + 1] <= n) {
        B++;
    }

    if (B == 0) {
        n--;
    }

    n -= len[B];
    i64 ans = sum[B];
    i64 pre = 0, prelen = 0;
    vector<int> vec;
    auto L = B + 1;

    while (n > prelen) {
        // cout<<"n="<<n<<" pre="<<pre<<" B="<<B<<" ans="<<ans<<endl;

        for (int x = !pre; x <= 9; x++) {
            i64 cc = pw[B] * L;
            if (B == 0 && pre == 0) {
                cc = 1;
            }
            if (n >= cc) {
                n -= cc;
                ans += (pre + x) * pw[B] + sum[B];
                // cout<<"n="<<n<<" x="<<x<<" ans="<<ans<<endl;
            } else {
                pre += x;
                prelen++;
                vec.push_back(x);
                B--;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        // cout<<"x="<<vec[i]<<endl;
        ans += vec[i];
    }

    cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
