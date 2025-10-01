#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> cnt(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i < n; i++) {
            if (cnt[i] > 2) {
                cnt[i+1] += cnt[i]-2;
            } else if (cnt[i] == 1) {
                cout<<"no"<<endl;
                return;
            }
    }
    if (cnt[n] % 2 == 0) {
        cout<<"yes"<<endl;
    } else {
        cout<<"no"<<endl;
    }
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


