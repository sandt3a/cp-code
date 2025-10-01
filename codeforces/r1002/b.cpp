#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == k) {
        int t = 1;
        for (int i = 1; i < n; i += 2, t++) {
            if (a[i] != t) {
                break;
            }
        }
        cout << t << "\n";
    } else {
        bool one = true;
        for (int i = 1; i < n-k+2; i++) {
            if (a[i] != 1) {
                one = false;
                break;
            }
        }
        if (one) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
