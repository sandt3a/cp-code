#include <bits/stdc++.h>
#include <cassert>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const string dir = "NEWS";

int get(char c) {
    for (int i = 0; i < 4; i++) {
        if (c == dir[i]) {
            return i;
        }
    }
    assert(false);
}

int turn_left(char c) {
    if (c == 'N') return 'W';
    if (c == 'W') return 'S';
    if (c == 'S') return 'E';
    if (c == 'E') return 'N';
    assert(false);
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
        string str;
        int x;
        cin >> str >> x;
     
        a[i] = {str[0], x};
    }

    char st = a[0].first;
    cout << n * 2 - 1 << " " << st << "\n";
    for (int i = 0; i < n; i++) {
        if (i) {
            if (a[i].first == turn_left(a[i - 1].first)) {
                cout << "L\n";
            } else {
                cout << "R\n";
            }
        }
        cout << "Z " << a[i].second << "\n";
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
