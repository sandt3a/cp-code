#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LIM = 100;

vector<i64> val, pre, cnt, precnt;

void init(int n = 2e5) {
    pre.assign(n + 1, 1);
    cnt.assign(n + 1, 0);
    val.assign(n + 1, 1);
    precnt.assign(n + 1, 0);

    pre[1] = val[1] = cnt[1] = precnt[1] = 1;
    for (int i = 2; i <= n; i++) {
        val[i] = pre[i - 1] * i % MOD;
        pre[i] = pre[i - 1] * val[i] % MOD;
        cnt[i] = precnt[i - 1] + 1;
        precnt[i] = min(precnt[i - 1] + cnt[i], 1000000001LL);
    }
    // for (int i = 1; i <= 100; i++) {

    // cout<<pre[i]<<" \n"[i == 100];
    // }
    // for (int i = 1; i <= 100; i++) {

    // cout<<val[i]<<" \n"[i == 100];
    // }
    // cout<<"!"<<precnt.back()<<endl;
}

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    i64 ans = 1;
    for (int i = 0; i < n && k; i++) {
        int x = a[i];
        i64 cc = x > LIM ? inf : cnt[x];
        if (k >= cc) {
            ans = ans * val[x] % MOD;
            k -= cc;
        } else {
            while (k) {
                ans = ans * x % MOD;
                k--;
                if (k == 0) break;
                int pos = lower_bound(precnt.begin(), precnt.end(), k) - precnt.begin();
                // cout<<"k="<<k<<" pos="<<pos<<endl;
                ans = ans * pre[pos - 1] % MOD;
                k -= precnt[pos - 1];
                x = pos;
                // cout<<"k="<<k<<" x="<<x<<endl;
            }
            break;
        }
        // 1 2 3 4 5 ans = 1
        // 2 3 4 5   ans = 1
        // 1 3 4 5   ans = 2
        // 3 4 5     ans = 2
        // 1 2 4 5   ans = 6
        // 2 4 5     ans = 6
        // 1 4 5     ans = 12
        // 4 5       ans = 12
        // 1 2 3 5   ans = 48
        // 
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
