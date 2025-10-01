#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    bitset<N> vec, cur;
    for (int i = 0; i < n; i++) {
        if (!vec.count(a[i])) {
            vec.set(a[i]);
            int j = i;
            while (j < n && cur & vec != vec) {
                cur.set(a[j]);
                j++;
            }
            i = j;
            cur.clear();
            ans++;
        } else {
            cur.set(a[i]);
        }
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
