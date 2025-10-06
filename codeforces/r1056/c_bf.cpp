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

    int ans = 0;
    for (int s = 0; s < (1<<n); s++) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = s>>i&1;
        }
        vector<int> c(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (b[j] == 0) {
                    c[i]++;
                }
            }
            for (int j = i+1; j < n; j++) {
                if (b[j] == 1) {
                    c[i]++;
                }
            }
        }
        if (a == c) {
            cout<<"b: ";
            for(auto x:b){
                cout<<x<<" ";
            }
            cout<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
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
