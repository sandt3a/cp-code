#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<string>> s(n, vector<string>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> setw(k) >> s[i][j];
        }
    }
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[s[i][j]]++;
        }
    }
    string niko;
    for (auto [k, v]: cnt) {
        if (v == 1) {
            niko = k;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == niko) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
